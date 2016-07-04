/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:46:53 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/21 14:50:38 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ground(t_env *e)
{
	t_point		a;
	t_point		dim;

	dim.x = 960;
	dim.y = 600;
	a.x = 0;
	a.y = 300;
	while (a.y < dim.y)
	{
		while (a.x < dim.x)
		{
			image_pixel_put(e, a, 0x5F5F5F);
			a.x++;
		}
		a.x = 0;
		a.y++;
	}
}

static void		sky(t_env *e)
{
	t_point		a;
	t_point		dim;

	dim.x = 960;
	dim.y = 300;
	a.x = 0;
	a.y = 0;
	while (a.y < dim.y)
	{
		while (a.x < dim.x)
		{
			image_pixel_put(e, a, 0x00CCFF);
			a.x++;
		}
		a.x = 0;
		a.y++;
	}
}

int				expose_hook(t_env *e)
{
	sky(e);
	ground(e);
	cast_wall(e);
	mlx_put_image_to_window(e->mlx, e->win, e->wall, 0, 0);
	return (0);
}
