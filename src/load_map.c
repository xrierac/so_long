/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 12:53:23 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	mlx->width = ft_strlen(mlx->map[0]);
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		if (i == 0 || mlx->map[i + 1] == 0)
					if (mlx->map[i][j] != 1)
					{
						ft_free_array(mlx->map);
						exit_error("Wrong map format\n", NULL)
					}






	}
}

void	split_map(t_mlx *mlx, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_inset(str[i], "10CEP\n") == 0)
			exit_error("Wrong map format\n", str);
		if (i < ft_strlen(str) && (str[i] == '\n' && str[i + 1] == '\n'))
			exit_error("Wrong map format\n", str);
	}
	if (str[0] == '\n' || str[ft_strlen(str) - 1] == '\n')
		exit_error("Wrong map format\n", str);
	mlx->map = ft_split(str);
	if (mlx->map == NULL)
		exit_error("Malloc failed\n", str);
	free(str);
}

void	load_map(t_mlx *mlx)
{
	int		fd;
	char	*str;
	char	*tmp;

	mlx->map_line = "a";
	str = ft_strdup("");
	if (str == NULL)
		exit_error("Malloc failed\n", NULL);
	fd = open(mlx->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n", str);
	while (mlx->map_line != NULL)
	{
		tmp = str;
		mlx->map_line = get_next_line(fd);
		str = ft_strjoin(str, mlx->map_line);
		free(tmp);
		if (mlx->map_line != NULL)
			free(mlx->map_line);
		if (str == NULL)
			exit_error("Malloc failed\n", NULL);
	}
	split_map(mlx, str);
	if (close(fd) == -1)
		exit_error("Error closing the file\n", NULL);
}
