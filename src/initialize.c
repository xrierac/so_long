/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:40:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/29 17:31:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_variables(t_map *map)
{
	map->col = 0;
	map->exit = 0;
	map->player = 0;
}

void	get_map_info(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
		   		map->col++;
			if (map->map[i][j] == 'E')
			{
				map->exit++;
				map->x_exit = j;
				map->y_exit = i;
			}
			if (map->map[i][j] == 'P')
			{
				map->player++;
				map->x_player = j;
				map->y_player = i;
			}
		}
	}
}
