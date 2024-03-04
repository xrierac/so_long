/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:18:50 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/04 16:24:49 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void move(int x, int y, t_map *map)
{
	map->img->ash->instances->x += x;
	map->img->ash->instances->y += y;
	ft_printf("Hello");
}
