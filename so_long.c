/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:46:16 by xriera-c          #+#    #+#             */
/*   Updated: 2023/12/15 14:44:42 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "unistd.h"

/*int	handle_no_event(void *game)
{
	return (0);
}
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
int	handle_input(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 123) //A Left
	if (keycode == 1 || keycode == 125) // S Down
	if (keycode == 2 || keycode == 124) // D Right
	if (keycode == 13 || keycode == 126) // W Up
	if (keycode == 53) // Esc
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (0);
}
*/
int	handle_input(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	char	*hero_path;
	void	*hero_image;
	int		width;
	int		height;

	width = 50;
	height = 50;
	hero_path = "./assets/hero/idle.xpm";
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, W_WIDTH, W_HEIGHT, "XaVi FaNtAsTiC AmAAZing GaMEE");
	if (game.win_ptr == NULL)
	{
		free(game.mlx_ptr);
		return (MLX_ERROR);
	}

	//Hooks//
	hero_image = mlx_xpm_file_to_image(game.mlx_ptr, hero_path, &width, &height); 
//	mlx_loop_hook(game.mlx_ptr, &handle_no_event, &game);
	mlx_key_hook(game.win_ptr, handle_input, (void *)0);
//	mlx_hook(game.win_ptr, 2, (1L << 0), handle_input, &game);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, hero_image, 50, 50);
	mlx_sync(5, a);
	mlx_loop(game.mlx_ptr);
	free(game.mlx_ptr);
}
