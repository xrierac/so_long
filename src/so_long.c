/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:28:41 by xriera-c          #+#    #+#             */
/*   Updated: 2024/02/25 13:02:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_error(char *str)
{
	ft_putstr_fd("so_long: ", 2);
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (write(2, "Wrong number of arguments\n", 26));
	if (argv)
		return (1);
	return (0);
}
