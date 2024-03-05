/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:50:11 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:11:23 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//void	collect(t_map *map
void	move(int x, int y, t_map *map)
{
	if (map->map[map->ply.y + y / SIZE][map->ply.x + x / SIZE] == '1')
		return ;
	map->img->ash->instances[0].x += x;
	map->img->ash->instances[0].y += y;
	map->ply.y = map->ply.y + y / SIZE;
	map->ply.x = map->ply.x + x / SIZE;
	ft_printf("%d %d\n", map->ply.x, map->ply.y);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move(SIZE, 0, map);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move(-SIZE, 0, map);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move(0, SIZE, map);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move(0, -SIZE, map);
}
