/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:16:13 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/29 15:44:13 by xriera-c         ###   ########.fr       */
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
	return (check_char(map));
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

int	check_map_error(t_map *map)
{
	int		i;

	i = -1;
	while (map->map[++i])
	{
		if (ft_strlen(map->map[i]) != (size_t)map->width)
			return (-1);
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (-1);
	}
	return (0);
}

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			if (map->



}
