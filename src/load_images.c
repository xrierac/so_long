/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:39 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/04 10:29:34 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	mlx_image_t	*load_image(char *path, mlx_t *mlx)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		exit_error("Problem loading image\n", NULL);
	img = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (img);
}

t_img	*import_images(mlx_t *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_error("ASS", NULL);
	img->tree = load_image("./textures/bush.xpm42", mlx);
	img->poke = load_image("./textures/poke.xpm42", mlx);
	img->ash = load_image("./textures/npc.xpm42", mlx);
	img->exit = load_image("./textures/imgexit.xpm42", mlx);
	img->floor = load_image("./textures/fond.xpm42", mlx);
	return (img);
}
