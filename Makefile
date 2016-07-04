# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2016/02/24 15:47:57 by lnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

SRC_PATH = srcs

OBJ_PATH = obj

CFLAGS = -Wall -Wextra -Werror

CPFLAGS = -I./usr/local/include -I./libft/includes -I ./inc

LFLAGS = -lmlx -framework OpenGl -framework AppKit -lm -L/usr/local/lib/

NAME = wolf3d

SRC_NAME = main.c \
		   image_pixel_put.c \
		   expose_hook.c \
		   key_p.c \
		   cast_wall.c \
		   map.c \
		   ray_cast.c \
		   ft_error.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIBFT_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(LIBFT_PATH) $(LFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPFLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

norme:
	@echo "* Norme wolf3d"
	norminette $(SRC)
	norminette inc/wolf.h
	@echo "* Norme Libft"
	make -C libft/ norme

.PHONY: clean fclean re all norme
