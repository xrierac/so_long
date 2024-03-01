/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:16:58 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:50:09 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_background(mlx_t *mlx, t_img	img, t_map *map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->height * SQ_SIZE)
	{
		j = 0;
		while (j < map->width * SQ_SIZE)
		{
			if(mlx_image_to_window(mlx, img.floor, j, i) < 0)
				exit_error(" ", map);
			j = j + SQ_SIZE;
		}
		i = i + SQ_SIZE;
	}
}
void	display(t_map map)
{
	mlx_t	*mlx;
	t_img	img;

	// Start mlx
	mlx = mlx_init(SQ_SIZE * map.width, SQ_SIZE * map.height, "So_Long", true);
	if (!mlx)
        exit_error("Couldn't start MLX\n", &map);
	ft_printf("Width: %d Height: %d\n", map.width, map.height);
	//Import image
	import_images(mlx, &img);
	create_background(mlx, img, &map);
	// Create a new image
	mlx_loop(mlx);
}
