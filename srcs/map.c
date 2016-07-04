/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:50:45 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 15:58:28 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		free_map(char **map)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void		fill(int *map, char **tmp)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		map[i] = ft_atoi(tmp[i]);
		i++;
	}
}

static int		**alloc_map(t_env *e)
{
	int			i;
	int			**map;

	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * 11)))
		ft_error(1, e);
	while (i < 11)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * 17)))
			ft_error(1, e);
		i++;
	}
	return (map);
}

int				**mapi(t_env *e)
{
	int			**map;
	char		**tmp;
	char		*str;
	int			fd;
	t_point		i;

	i.x = 0;
	map = alloc_map(e);
	fd = open("map.txt", O_RDONLY);
	while ((i.y = get_next_line(fd, &str)) > 0)
	{
		if (i.y == -1)
			ft_error(3, e);
		tmp = ft_strsplit(str, ' ');
		fill(map[i.x], tmp);
		free(str);
		free_map(tmp);
		i.x++;
	}
	return (map);
}
