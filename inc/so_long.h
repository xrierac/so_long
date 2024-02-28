/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:25 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/28 12:30:45 by xriera-c         ###   ########.fr       */
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

# ifndef SQ_SIZE
#  define SQ_SIZE 64
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef struct	s_map
{
	int		width;
	int		height;
	char	*path;
	char 	*line;
	char	**map;
	int		col;
	int		exit;
	int		player;
}	t_map;

//Map parsing//
int		check_map_line(t_map *map);
int		check_map_error(t_map *map);
int		check_path(char *str);

void	exit_error(char *str, t_map *map);
int		map_error(char *str);
void	load_map(t_map *map);

//get_next_line//

char	*get_next_line(int fd);
char	*get_cache(char *cache, char *read_return, int fd);
char	*get_next_line(int fd);
char	*next_line(int fd, char *read_return, char *cache);
char	*free_mem(char *res, char *tmp);

#endif
