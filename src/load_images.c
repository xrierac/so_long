/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:39 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 15:55:04 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	mlx_image_t	*load_image(char *path, t_map *map)
{
	xpm_t		*xpm;
	mlx_image_t	*img;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		exit_error("Problem loading image\n", map);
	img = mlx_texture_to_image(map->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (mlx_resize_image(img, SIZE, SIZE) != 1)
		exit_error("Problem resizing the image\n", map);
	return (img);
}

t_img	*import_images(t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit_error("MAlloc failed\n", map);
	img->tree = load_image("./textures/bush.xpm42", map);
	img->poke = load_image("./textures/poke.xpm42", map);
	img->ash = load_image("./textures/npc.xpm42", map);
	img->exit = load_image("./textures/imgexit.xpm42", map);
	img->floor = load_image("./textures/fond.xpm42", map);
	img->ashrmv = load_image("./textures/npcrightmv.xpm42", map);
	img->ashlmv = load_image("./textures/npcleftmv.xpm42", map);
	img->ashbmv = load_image("./textures/npcbackmv.xpm42", map);
	return (img);
}
