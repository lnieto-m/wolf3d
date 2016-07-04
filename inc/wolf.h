/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:43:11 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 15:56:05 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*wall;
	int				*data_wall;
	int				x;
	int				y;
	int				bpp;
	int				end;
	int				**map;
	int				lateral;
	int				dir;
	t_vec			pos;
	double			angle_cam;
}					t_env;

int					**mapi(t_env *e);
int					image_pixel_put(t_env *e, t_point a, int color);
int					expose_hook(t_env *e);
int					key_p(int keycode, t_env *e);
void				cast_wall(t_env *e);
void				ft_error(int err, t_env *e);
double				ray_cast(t_env *e, double angle);

#endif
