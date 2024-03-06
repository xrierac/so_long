/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/06 09:58:58 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_map_info(t_map *map)
{
	int	i;
	int	j;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				map->col++;
			if (map->map[i][j] == 'E')
				exit++;
			if (map->map[i][j] == 'P')
				player++;
		}
	}
	if (player != 1 || exit != 1)
		return (-1);
	return (0);
}

static void	split_map(t_map *map)
{
	map->map = ft_split(map->line, '\n');
	if (map->map == NULL)
		exit_error("Malloc failed\n", map);
	map->copy = ft_split(map->line, '\n');
	if (map->copy == NULL)
		exit_error("Malloc failed\n", map);
	free(map->line);
	map->line = NULL;
	map->width = ft_strlen(map->map[0]);
}

static int	get_line(t_map *map, int fd)
{
	char	*tmp;
	char	*str;

	map->line = ft_strdup("");
	if (map->line == NULL)
		return (-1);
	while (1)
	{
		tmp = map->line;
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->line = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		if (map->line == NULL)
		{
			close(fd);
			return (-1);
		}
		map->height++;
	}
	return (0);
}

void	load_map(t_map *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map. Fat fingers, probably\n", map);
	if (get_line(map, fd) == -1)
		exit_error("Malloc failed. Buy more RAM\n", map);
	close(fd);
	if (map->height == 0 || check_map_line(map) == -1)
		exit_error("Wrong map format. Try doing it properly?\n", map);
	split_map(map);
	if (check_map_error(map) == -1)
		exit_error("Wrong map format. Be better, pls\n", map);
	if (get_map_info(map) == -1 || map->col < 1)
		exit_error("Wrong number of objects. Can you count?\n", map);
	find_player(map);
	flood_fill(map, map->ply.x, map->ply.y);
	if (test_flood(map) == -1)
		exit_error("Unplayable map. Try harder\n", map);
}
