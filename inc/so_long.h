/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:25 by xriera-c          #+#    #+#             */
/*   Updated: 2024/03/05 10:07:34 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"

# ifndef SIZE
#  define SIZE 50
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_img
{
	mlx_image_t	*tree;
	mlx_image_t	*poke;
	mlx_image_t	*ash;
	mlx_image_t	*exit;
	mlx_image_t	*floor;
}	t_img;

typedef struct	s_map
{
	int		width;
	int		height;
	char 	*line;
	char	**map;
	int		col;
	t_img	*img;
	t_point	ply;
	mlx_t	*mlx;
	int		w_width;
	int		w_height;
}	t_map;

void	initialize_variables(t_map *map);
t_img	*import_images(t_map *map);
void	my_keyhook(mlx_key_data_t keydata, void *map);
void	move(int x, int y, t_map *map);

//Map parsing//
int		check_map_line(t_map *map);
int		check_map_error(t_map *map);
int		check_path(char *str);

void	exit_error(char *str, t_map *map);
int		map_error(char *str);
void	load_map(t_map *map, char *path);

//MLX//
void	display(t_map *map);

//get_next_line//

char	*get_next_line(int fd);
char	*get_cache(char *cache, char *read_return, int fd);
char	*get_next_line(int fd);
char	*next_line(int fd, char *read_return, char *cache);
char	*free_mem(char *res, char *tmp);

#endif
