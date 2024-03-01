/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:16:58 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/01 11:41:41 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_background(mlx_t *mlx, xpm_t *xpm, t_map *map)
{
	int			i;
	mlx_image_t	*img;

	i = 0;
	img = mlx_texture_to_image(mlx, &xpm->texture);
	free(xpm);
	while (i < map->width)
	{
		if(mlx_image_to_window(mlx, img, i * SQ_SIZE, 0) < 0)
			exit_error(" ", map);
		i++;
	}
}
void	display(t_map map)
{
	mlx_t	*mlx;
	xpm_t	*xpm;

	// Start mlx
	mlx = mlx_init(SQ_SIZE * map.width, SQ_SIZE * map.height, "So_Long", true);
	if (!mlx)
        exit_error("Couldn't start MLX\n", &map);
	ft_printf("Width: %d Height: %d\n", map.width, map.height);
	//Import image
	xpm = mlx_load_xpm42("./textures/fond.xpm42");
	if (!xpm)
		exit_error("Error loading image\n", &map);
	create_background(mlx, xpm, &map);
	// Create a new image
	mlx_loop(mlx);
}
