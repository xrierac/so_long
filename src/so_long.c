/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 12:32:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *str, char *malloced)
{
	if (malloced != NULL)
		free(malloced);
	ft_putstr_fd("so_long: Error: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#define WIDTH 5120
#define HEIGHT 2880

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Create a new image
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	if (!img)
		error();

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/
int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		i;

	i = 0;
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	mlx.path = argv[1];
	/*
	if (argv)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
		return (1);
	*/	
	get_size(&mlx);
	load_map(&mlx);
	ft_printf("Width: %d Height: %d\n", mlx.width, mlx.height);
	while (mlx.map[i])
	{
		ft_printf("%s\n", mlx.map[i]);
		i++;
	}
	return (0);
}
