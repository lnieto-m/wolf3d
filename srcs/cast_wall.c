/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:43:07 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 16:30:13 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		colors(t_env *e)
{
	if (e->dir && e->lateral)
		return (0xFF0000);
	else if (!e->dir && e->lateral)
		return (0x00FF00);
	else if (e->dir && !e->lateral)
		return (0xFFFF00);
	else
		return (0x0000FF);
}

/*
** angle.x = direction de la camera;
** angle.y = angle de vision;
** height = auteur des murs sur l'ecran, obtenu a partir de ray_cast;
*/

void			cast_wall(t_env *e)
{
	int			height;
	t_point		p;
	t_vec		angle;
	int			color;

	angle.x = e->angle_cam;
	angle.y = angle.x - (M_PI / 6);
	p.x = 960;
	p.y = 0;
	height = 0;
	color = 0;
	while (angle.y <= angle.x + (M_PI / 6))
	{
		height = 645 / ray_cast(e, angle.y);
		p.y = 300 - (height / 2);
		color = colors(e);
		while (p.y < 600 - (300 - (height / 2)))
		{
			image_pixel_put(e, p, color);
			p.y++;
		}
		angle.y += (M_PI / 3) / 960;
		p.x--;
	}
}
