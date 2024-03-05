/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:16:58 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:57:03 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	print_to_map(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	int32_t	i;
	int32_t	j;

	i = x * SIZE;
	j = y * SIZE;
	if (mlx_image_to_window(mlx, img, i, j) < 0)
		return (-1);
	return (0);
}

void	create_map(t_map *map)
{
	t_point		p;
	mlx_image_t	*pic;

	p.y = -1;
	while (++p.y < map->height)
	{
		p.x = -1;
		while (++p.x < map->width)
		{
			if (print_to_map(map->mlx, map->img->floor, p.x, p.y) < 0)
				exit_error("Error while displaying map\n", map);
			if (map->map[p.y][p.x] == 'C')
				pic = map->img->poke;
			if (map->map[p.y][p.x] == 'P')
				pic = map->img->ash;
			if (map->map[p.y][p.x] == 'E')
				pic = map->img->exit;
			if (map->map[p.y][p.x] == '1')
				pic = map->img->tree;
			if (map->map[p.y][p.x] == '0')
				pic = map->img->floor;
			if (print_to_map(map->mlx, pic, p.x, p.y) < 0)
				exit_error("Error while displaying map\n", map);
		}
	}
}

void	display(t_map *map)
{
	map->mlx = mlx_init(map->w_width, map->w_height, "So_Long", true);
	if (!map->mlx)
        exit_error("Couldn't start MLX\n", map);
	map->img = import_images(map);
	create_map(map);
	// Create a new image
	map->ply.x = map->img->ash->instances->x / SIZE;
	map->ply.y = map->img->ash->instances->y / SIZE;
	mlx_key_hook(map->mlx, &my_keyhook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}
