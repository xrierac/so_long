/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:16:58 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/04 16:44:11 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	print_to_map(mlx_t *mlx, mlx_image_t *img, int x, int y)
{
	int32_t	i;
	int32_t	j;

	i = x * SQ_SIZE;
	j = y * SQ_SIZE;
	if (mlx_image_to_window(mlx, img, i, j) < 0)
		return (-1);
	return (0);
}

void	create_map(mlx_t *mlx,  t_map *map)
{
	t_point		p;
	mlx_image_t	*pic;

	p.y = -1;
	while (++p.y < map->height)
	{
		p.x = -1;
		while (++p.x < map->width)
		{
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
			if (print_to_map(mlx, pic, p.x, p.y) < 0)
				exit_error("Error while displaying map\n", map);
		}
	}
}

void	display(t_map *map)
{
	mlx_t	*mlx;

	// Start mlx
	mlx = mlx_init(SQ_SIZE * map->width, SQ_SIZE * map->height, "So_Long", true);
	if (!mlx)
        exit_error("Couldn't start MLX\n", map);
	ft_printf("Width: %d Height: %d\n", map->width, map->height);
	//Import image
	map->img = import_images(mlx);
	create_map(mlx, map);
	// Create a new image
	ft_printf("Hey %d\n", map->img->ash->instances->x);
	ft_printf("Hey %d\n", map->img->ash->instances[0].x);
	mlx_key_hook(mlx, &my_keyhook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
