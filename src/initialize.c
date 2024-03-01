/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:40:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/01 10:40:27 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize_variables(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->col = 0;
	map->exit = 0;
	map->player = 0;
	map->line = NULL;
	map->map = NULL;
}
