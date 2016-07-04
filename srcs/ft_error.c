/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:41:26 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/02/24 15:57:26 by lnieto-m         ###   ########.fr       */
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

void			ft_error(int err, t_env *e)
{
	if (err == 1)
		ft_putendl("Malloc error");
	else if (err == 2)
	{
		free_map(e->map);
		ft_putendl("Mlx initialisation failed");
	}
	else if (err == 3)
		ft_putendl("GNL error");
	exit(EXIT_FAILURE);
}
