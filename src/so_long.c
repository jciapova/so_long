/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janka <janka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:34 by jciapova          #+#    #+#             */
/*   Updated: 2023/07/06 14:31:13 by janka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include "../libft/libft.h"

// TO DO = flood fill, bonus?

int	close_window()
{
	exit(0);
	return(0);
}

int	main(int argc, char **argv)
{
	t_program	start;
	
	if (argc != 2)
		return (0);
	else
	{
		ft_memset(&start, 0, sizeof(start));
		start.mlx = mlx_init();
		start_map(argv[1], &start);
		map_size(&start);
		start.win = mlx_new_window(start.mlx, start.map_size_x * 60, start.map_size_y * 60, "So Long");
		draw_map(&start);
		check_map(&start);
		mlx_hook(start.win, 2, 1L<<0, move_player, &start);
		mlx_hook(start.win, 17, 1L<<2, close_window, &start);
		mlx_loop(start.mlx);
	}
	return (0);
}
