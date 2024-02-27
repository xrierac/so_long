/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 17:40:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	get_size(t_mlx	*mlx)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	line = "a";
	fd = open(mlx->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n", mlx);
	while (line != NULL)
		{
			line = get_next_line(fd);
			if (i == 0)
				mlx->width = ft_strlen(line) - 1;
			if (line != NULL)
				free(line);
			i++;
		}
	mlx->height = i;
	if (close(fd) == -1)
		exit_error("Error closing the file\n", mlx);
}

static void	split_map(t_mlx *mlx)
{
	mlx->map = ft_split(mlx->line, '\n');
	if (mlx->map == NULL)
		exit_error("Malloc failed\n", mlx);
	free(mlx->line);
	mlx->line = NULL;
}

static int	get_line(t_mlx *mlx, int fd)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	mlx->line = ft_strdup("");
	if (mlx->line == NULL)
		return (-1);
	while (i++ < mlx->height)
	{
		tmp = mlx->line;
		str = get_next_line(fd);
		mlx->line = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		if (mlx->line == NULL)
			return (-1);
	}
	return (0);
}

void	load_map(t_mlx *mlx)
{
	int		fd;

	get_size(mlx);
	if (mlx->width < 4)
		exit_error("Wrong map format\n", mlx);
	fd = open(mlx->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n", mlx);
	if (get_line(mlx, fd) == -1)
		exit_error("Malloc failed\n", mlx);
	if (check_map_format(mlx) == -1)
	   exit_error("Wrong map format\n", mlx);	
	split_map(mlx);
	if (check_map_error(mlx) == -1)
		exit_error("Wrong map format\n", mlx);
	if (close(fd) == -1)
		exit_error("Error closing the file\n", mlx);
}
