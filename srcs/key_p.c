/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:57:18 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 16:40:35 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		free_map(int **map)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void		forward(t_env *e, int keycode)
{
	t_vec	move;

	move.x = (0.05 * sin(e->angle_cam));
	move.y = (0.05 * cos(e->angle_cam));
	if (keycode == 13)
	{
		if (e->map[(int)(e->pos.y + move.y)][(int)(e->pos.x + move.x)] != 1)
		{
			e->pos.y += move.y;
			e->pos.x += move.x;
			ft_bzero(e->data_wall, 900 * 600);
			expose_hook(e);
		}
	}
	else if (keycode == 1)
	{
		if (e->map[(int)(e->pos.y - move.y)][(int)(e->pos.x - move.x)] != 1)
		{
			e->pos.y -= move.y;
			e->pos.x -= move.x;
			ft_bzero(e->data_wall, 900 * 600);
			expose_hook(e);
		}
	}
}

static void		lateral(t_env *e, int keycode)
{
	t_vec	movey;

	movey.x = (0.05 * sin(e->angle_cam + M_PI_2));
	movey.y = (0.05 * cos(e->angle_cam + M_PI_2));
	if (keycode == 0)
	{
		if (e->map[(int)(e->pos.y + movey.y)][(int)(e->pos.x + movey.x)] != 1)
		{
			e->pos.y += movey.y;
			e->pos.x += movey.x;
			ft_bzero(e->data_wall, 900 * 600);
			expose_hook(e);
		}
	}
	else if (keycode == 2)
	{
		if (e->map[(int)(e->pos.y - movey.y)][(int)(e->pos.x - movey.x)] != 1)
		{
			e->pos.y -= movey.y;
			e->pos.x -= movey.x;
			ft_bzero(e->data_wall, 900 * 600);
			expose_hook(e);
		}
	}
}

int				key_p(int keycode, t_env *e)
{
	if (keycode == 13 || keycode == 1)
		forward(e, keycode);
	if (keycode == 0 || keycode == 2)
		lateral(e, keycode);
	if (keycode == 124)
	{
		e->angle_cam -= (M_PI / 3) / 30;
		ft_bzero(e->data_wall, 900 * 600);
		expose_hook(e);
	}
	else if (keycode == 123)
	{
		e->angle_cam += (M_PI / 3) / 30;
		ft_bzero(e->data_wall, 900 * 600);
		expose_hook(e);
	}
	if (keycode == 53)
	{
		free_map(e->map);
		mlx_destroy_image(e->mlx, e->wall);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
