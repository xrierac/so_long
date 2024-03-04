/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/04 16:47:09 by xriera-c         ###   ########.fr       */
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
	t_map	*map;
	int		i;

	i = 0;
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	initialize_variables(&map);
	if (check_path(argv[1]) == -1)
		exit_error("Wrong map file\n", &map);
	load_map(&map, argv[1]);
	display(&map);
	while (map.map[i])
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	ft_free_array(map.map);
	return (0);
}
