/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:16:13 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 17:37:48 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_map_format(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (mlx->line[++i])
	{
		if (ft_inset(mlx->line[i], "10CEP\n") == 0)
			return (-1);
		if (i > 0 && (mlx->line[i] == '\n' && mlx->line[i - 1] == '\n'))
			return (-1);
	}
	if (mlx->line[0] == '\n' || mlx->line[ft_strlen(mlx->line) - 1] == '\n')
			return (-1);
	return (0);
}

int	check_path(char *str)
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

int	check_map_error(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (mlx->map[++i])
	{
		if (ft_strlen(mlx->map[i]) != (size_t)mlx->width)
			return (-1);
	}
	return (0);
}
