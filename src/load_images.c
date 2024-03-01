/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:39 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/01 18:51:56 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_image(char *path, mlx_image_t *img, mlx_t *mlx)
{
	xpm_t	*xpm;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		exit_error("Problem loading image\n", NULL);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
}

void	import_images(mlx_t *mlx, t_img *img)
{
	img = malloc(sizeof(t_img));
	if (!img)
		exit_error("ASS", NULL);
	load_image("./textures/bush.xpm42", img->tree, mlx);
	load_image("./textures/poke.xpm42", img->poke, mlx);
	load_image("./textures/npc.xpm42", img->ash, mlx);
	load_image("./textures/imgexit.xpm42", img->exit, mlx);
	load_image("./textures/fond.xpm42", img->floor, mlx);
}
