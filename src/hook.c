/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:50:11 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/04 16:46:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void my_keyhook(mlx_key_data_t keydata, t_map *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(NULL);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		param->img->ash->instances[0].x += 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move(-SQ_SIZE, 0, param);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move(0, SQ_SIZE, param);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move(0, -SQ_SIZE, param);
}
