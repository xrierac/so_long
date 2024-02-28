/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:30:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	void	get_size(t_map	*map)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	line = "a";
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n", map);
	while (line != NULL)
		{
			line = get_next_line(fd);
			if (i == 0)
				map->width = ft_strlen(line) - 1;
			if (line != NULL)
				free(line);
			i++;
		}
	map->height = i;
	if (close(fd) == -1)
		exit_error("Error closing the file\n", map);
}

static void	split_map(t_map *map)
{
	map->map = ft_split(map->line, '\n');
	if (map->map == NULL)
		exit_error("Malloc failed\n", map);
	free(map->line);
	map->line = NULL;
}

static int	get_line(t_map *map, int fd)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	map->line = ft_strdup("");
	if (map->line == NULL)
		return (-1);
	while (i++ < map->height)
	{
		tmp = map->line;
		str = get_next_line(fd);
		map->line = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		if (map->line == NULL)
			return (-1);
	}
	return (0);
}

void	load_map(t_map *map)
{
	int		fd;

	get_size(map);
	if (map->width < 4)
		exit_error("Wrong map format\n", map);
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open the map\n", map);
	if (get_line(map, fd) == -1)
		exit_error("Malloc failed\n", map);
	if (check_map_line(map) == -1)
	   exit_error("Wrong map format\n", map);	
	split_map(map);
	if (check_map_error(map) == -1)
		exit_error("Wrong map format\n", map);
	if (close(fd) == -1)
		exit_error("Error closing the file\n", map);
}
