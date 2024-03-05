/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:40:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 16:30:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_variables(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->col = 0;
	map->line = NULL;
	map->map = NULL;
	map->copy = NULL;
	map->mlx = NULL;
	map->img = NULL;
	map->steps = 0;
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->ply.x = j;
				map->ply.y = i;
			}
			j++;
		}
		i++;
	}
}
