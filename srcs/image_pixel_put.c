/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:13:57 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/19 15:07:08 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			image_pixel_put(t_env *e, t_point a, int color)
{
	if ((a.x < 0 || a.x >= e->x / 4) || (a.y < 0 || a.y > e->y))
		return (0);
	e->data_wall[a.x + e->x / 4 * a.y] = color;
	return (1);
}
