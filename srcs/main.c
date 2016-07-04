/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:42:24 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 16:01:39 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		def(t_env *e)
{
	e->x = 960;
	e->y = 600;
	e->bpp = 8;
	e->end = 1;
	e->pos.x = 2.5;
	e->pos.y = 2.5;
	e->map = mapi(e);
	e->angle_cam = 0;
}

int				main(void)
{
	t_env		e;

	def(&e);
	if ((e.mlx = mlx_init()) == NULL
		|| (e.win = mlx_new_window(e.mlx, e.x, e.y, "Wolf3d")) == NULL
		|| (e.wall = mlx_new_image(e.mlx, e.x, e.y)) == NULL)
		ft_error(2, &e);
	e.data_wall = (int *)mlx_get_data_addr(e.wall, &e.bpp, &e.x, &e.end);
	mlx_hook(e.win, 2, (1L << 0), key_p, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
