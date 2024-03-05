/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 16:33:09 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *msg, t_map *map)
{
	if (map->line != NULL)
		free(map->line);
	if (map->map != NULL)
		ft_free_array(map->map);
	if (map->copy != NULL)
		ft_free_array(map->copy);
	if (map->mlx != NULL)
		mlx_terminate(map->mlx);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	initialize_variables(&map);
	if (check_path(argv[1]) == -1)
		exit_error("Wrong map file\n", &map);
	load_map(&map, argv[1]);
	map.w_width = map.width * SIZE;
	map.w_height = map.height * SIZE;
	display(&map);
	while (map.map[i])
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	ft_free_array(map.map);
	ft_free_array(map.copy);
	free(map.img);
	return (0);
}
