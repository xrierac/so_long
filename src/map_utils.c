/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:16:13 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/06 09:54:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_map_line(t_map *map)
{
	int	i;

	i = -1;
	while (map->line[++i])
	{
		if (ft_inset(map->line[i], "10CEP\n") == 0)
			return (-1);
		if (i > 0 && (map->line[i] == '\n' && map->line[i - 1] == '\n'))
			return (-1);
	}
	if (map->line[0] == '\n' || map->line[ft_strlen(map->line) - 1] == '\n')
		return (-1);
	return (0);
}

int	check_path(char *path)
{
	int		len;
	char	*substr;
	int		fd;

	len = ft_strlen(path);
	substr = &path[len - 4];
	if (len < 5 || path[len - 5] == '/')
		return (-1);
	if (ft_strncmp(substr, ".ber", 4) != 0)
		return (-1);
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (-1);
	}
	return (0);
}

int	check_map_error(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		if (ft_strlen(map->map[i]) != (size_t)map->width)
			return (-1);
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (-1);
		if (i == 0 || i == map->height - 1)
		{
			j = -1;
			while (map->map[i][++j])
				if (map->map[i][j] != '1')
					return (-1);
		}
	}
	return (0);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map->copy[y][x] == '1' || map->copy[y][x] == '2')
		return ;
	map->copy[y][x] = '2';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	test_flood(t_map *map)
{
	t_point	p;

	p.x = -1;
	while (map->copy[++p.x])
	{
		p.y = -1;
		while (map->copy[p.x][++p.y])
		{
			if (map->copy[p.x][p.y] != '1' && map->copy[p.x][p.y] != '2')
			{
				ft_free_array(map->copy);
				map->copy = NULL;
				return (-1);
			}
		}
	}
	ft_free_array(map->copy);
	map->copy = NULL;
	return (0);
}
