/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:46:16 by xriera-c          #+#    #+#             */
/*   Updated: 2023/12/12 11:59:12 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "XaVi FaNtAsTiC AmAAZing GaMEE");
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
}
