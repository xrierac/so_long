/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:25 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/27 17:37:55 by xriera-c         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef struct	s_mlx
{
	void	*window;
	void	*context;
	int		width;
	int		height;
	double	delta_time;
	char	*path;
	char 	*line;
	char	**map;
}	t_mlx;

typedef struct s_mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	int32_t			count;
	bool			enabled;
	void*			context;
}	t_mlx_image;

//Map parsing//
int		check_map_format(t_mlx *mlx);
int		check_map_error(t_mlx *mlx);
int		check_path(char *str);

void	exit_error(char *str, t_mlx *mlx);
int		map_error(char *str);
void	load_map(t_mlx *mlx);

//get_next_line//

char	*get_next_line(int fd);
char	*get_cache(char *cache, char *read_return, int fd);
char	*get_next_line(int fd);
char	*next_line(int fd, char *read_return, char *cache);
char	*free_mem(char *res, char *tmp);

#endif
