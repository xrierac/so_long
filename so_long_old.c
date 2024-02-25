/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:46:16 by xriera-c          #+#    #+#             */
/*   Updated: 2023/12/22 12:36:16 by xriera-c         ###   ########.fr       */
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

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

int	handle_input(int keycode, t_win *game)
{
//	if (keycode == 0 || keycode == 123) //A Left
//	if (keycode == 1 || keycode == 125) // S Down
//	if (keycode == 2 || keycode == 124) // D Right
//	if (keycode == 13 || keycode == 126) // W Up
	if (keycode == 53)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	return (0);
}

int	main(void)
{
	t_win		game;
	t_asset		floor;
	int			i;
	int			j;

	i = 0;
	game.mlx_ptr = mlx_init();
	game.width = 800;
	game.height = 800;
	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width, game.height, "XaVi FaNtAsTiC AmAAZing GaMEE");
	if (game.win_ptr == NULL)
	{
		free(game.mlx_ptr);
		return (MLX_ERROR);
	}

	//Hooks//
	floor.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "./textures/Tiles.xpm", &game.width, &game.height); 
//	mlx_loop_hook(game.mlx_ptr, &handle_no_event, &game);
	mlx_key_hook(game.win_ptr, handle_input, (void *)0);
//	mlx_hook(game.win_ptr, 2, (1L << 0), handle_input, &game);
	while (i < 800)
	{
		j = 0;
		while (j < 800)
		{
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, floor.img_ptr, i, j);
			j += 50;
		}
		i += 50;
	}
	mlx_loop(game.mlx_ptr);
	free(game.mlx_ptr);
}
