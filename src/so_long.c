/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/26 12:04:55 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *str)
{
	ft_putstr_fd("so_long: Error: ", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	mlx.path = argv[1];
	/*
	load_map(argv[1]);
	if (argv)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
		return (1);
		*/
	get_size(&mlx);
	ft_printf("Width: %d Height: %d\n", mlx.width, mlx.height);
	return (0);
}
