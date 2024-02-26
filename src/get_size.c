/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:40:59 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/26 12:11:03 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_size(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		i;

	line = "a";
	fd = open(mlx->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n");
	i = -1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (i == -1)
			mlx->width = ft_strlen(line) - 1;
		free(line);
		i++;
	}
	mlx->height = i;
	if (close(fd) == -1)
		exit_error("Error closing the file\n");
}
