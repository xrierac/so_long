/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:30:37 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *msg, t_map *map)
{
	if (map->line != NULL)
		free(map->line);
	if (map->map != NULL)
		ft_free_array(map->map);
	ft_putstr_fd("so_long: Error: ", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/*

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (map_image_to_window(map, img, 0, 0) < 0)
        error();


	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	map_delete_image(map, img);
	map_terminate(map);
	return (EXIT_SUCCESS);
}
*/
int	main(int argc, char *argv[])
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	xpm_t		*xpm;
	int		i;

	i = 0;
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	if (check_path(argv[1]) == -1)
		exit_error("Wrong map file\n", &map);
	map.path = argv[1];
	load_map(&map);
	// Start mlx
	mlx = mlx_init(SQ_SIZE * map.width, SQ_SIZE * map.height, "Pocketmon", true);
	if (!mlx)
        exit_error("Couldn't start MLX\n", &map);
	ft_printf("Width: %d Height: %d\n", map.width, map.height);
	//Import iamge
	xpm = mlx_load_xpm42("./textures/npc.xpm42");
	if (!xpm)
		exit_error("Error loading image\n", &map);
	// Create a new image
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		exit_error(" ", &map);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit_error(" ", &map);
	mlx_loop(mlx);
	while (map.map[i])
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	return (0);
}
