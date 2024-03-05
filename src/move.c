/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:45:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 15:21:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_actions(t_map *map, int x, int y)
{
	map->img->ashlmv->instances->x += x;
	map->img->ashrmv->instances->x += x;
	map->img->ashbmv->instances->x += x;
	map->img->ash->instances->x += x;
	map->img->ashlmv->instances->y += y;
	map->img->ashrmv->instances->y += y;
	map->img->ashbmv->instances->y += y;
	map->img->ash->instances->y += y;
	print_steps(map);
	collectibles(map);
	good_exit(map);
}

void	move_right(t_map *map)
{
	if (map->map[map->ply.y][map->ply.x + 1] == '1')
		return ;
	map->ply.x++;
	move_actions(map, SIZE, 0);
	map->img->ash->enabled = 0;
	map->img->ashlmv->enabled = 0;
	map->img->ashbmv->enabled = 0;
	map->img->ashrmv->enabled = 1;
}

void	move_left(t_map *map)
{
	if (map->map[map->ply.y][map->ply.x - 1] == '1')
		return ;
	map->ply.x--;
	move_actions(map, -SIZE, 0);
	map->img->ash->enabled = 0;
	map->img->ashlmv->enabled = 1;
	map->img->ashbmv->enabled = 0;
	map->img->ashrmv->enabled = 0;
}

void	move_down(t_map *map)
{
	if (map->map[map->ply.y + 1][map->ply.x] == '1')
		return ;
	map->ply.y++;
	move_actions(map, 0, SIZE);
	map->img->ash->enabled = 1;
	map->img->ashlmv->enabled = 0;
	map->img->ashbmv->enabled = 0;
	map->img->ashrmv->enabled = 0;
}

void	move_up(t_map *map)
{
	if (map->map[map->ply.y - 1][map->ply.x] == '1')
		return ;
	map->ply.y--;
	move_actions(map, 0, -SIZE);
	map->img->ash->enabled = 0;
	map->img->ashlmv->enabled = 0;
	map->img->ashbmv->enabled = 1;
	map->img->ashrmv->enabled = 0;
}
