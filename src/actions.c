/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:13:23 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 15:55:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collectibles(t_map *map)
{
	int		i;
	t_img	*img;

	img = map->img;
	if (map->map[map->ply.y][map->ply.x] == 'C')
	{
		map->map[map->ply.y][map->ply.x] = '0';
		i = 0;
		while (map->col)
		{
			if (img->poke->instances[i].x == img->ash->instances->x
				&& img->poke->instances[i].y == img->ash->instances->y)
				break ;
			i++;
		}
		map->img->poke->instances[i].enabled = 0;
		map->col--;
	}
}

void	good_exit(t_map *map)
{
	if (map->col == 0 && map->map[map->ply.y][map->ply.x] == 'E')
		mlx_close_window(map->mlx);
}

void	print_steps(t_map *map)
{
	map->steps++;
	ft_printf("Number of steps: %d\n", map->steps);
}
