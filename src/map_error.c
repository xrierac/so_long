/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:53:38 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 11:50:37 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_format(char *str)
{
	int		len;
	char	*substr;

	len = ft_strlen(str);
	if (len < 5)
		return (-1);
	substr = &str[len - 4];
	if (ft_strncmp(substr, ".ber", 4) != 0)
		return (-1);
	return (0);
}

static int	check_walls(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 
	if (
	if (str[0] != 1 || str[ft_strlen(str - 1)] != 1)
		return (-1);
}


int	map_error(t_mlx *mlx)
{
	if (check_format(mlx->path) == -1)
		exit_error("Wrong map name format\n");

