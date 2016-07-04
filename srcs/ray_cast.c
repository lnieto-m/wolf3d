/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:02:45 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 15:33:21 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		find(t_env *e, t_vec pos)
{
	if (e->lateral && e->pos.y - pos.y > 0)
		e->dir = 1;
	else if (!e->lateral && e->pos.x - pos.x > 0)
		e->dir = 1;
	else
		e->dir = 0;
}

double			ray_cast(t_env *e, double angle)
{
	t_vec	pos;
	t_vec	cosi;
	double	dist;

	dist = 0.01;
	pos.x = e->pos.x;
	pos.y = e->pos.y;
	e->lateral = 0;
	cosi.x = sin(angle) * 0.001;
	cosi.y = cos(angle) * 0.001;
	while (e->map[(int)pos.y][(int)pos.x] == 0)
	{
		pos.y += cosi.y;
		if (e->map[(int)pos.y][(int)pos.x] != 0)
			e->lateral = 1;
		pos.x += cosi.x;
		dist += 0.001;
	}
	find(e, pos);
	return (dist * cos(e->angle_cam - angle));
}
