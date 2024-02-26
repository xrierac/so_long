/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/26 17:05:34 by xriera-c         ###   ########.fr       */
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
		if (line != NULL)
			free(line);
		i++;
	}
	mlx->height = i;
	if (close(fd) == -1)
		exit_error("Error closing the file\n");
}

void	load_map(t_mlx *mlx)
{
	int		fd;
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	fd = open(mlx->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n");
	while (i < mlx->height)
	{
		tmp = str;
		str = ft_strjoin(str, get_next_line(fd));
		free(tmp);
		i++;
	}
	mlx->map = ft_split(str, '\n');
	if (close(fd) == -1)
		exit_error("Error closing the file\n");
}
