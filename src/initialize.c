/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:40:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:09:12 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_variables(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->col = 0;
	map->line = NULL;
	map->map = NULL;
	map->ply.x = 0;
	map->ply.y = 0;
	map->mlx = NULL;
	map->img = NULL;
}
