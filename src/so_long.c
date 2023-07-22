/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:34 by jciapova          #+#    #+#             */
/*   Updated: 2023/07/22 14:44:35 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../printf/ft_printf.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include "../libft/libft.h"
#include <stdbool.h>

void	ber_check(char *argv)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 4))
	{
		ft_printf("Error: File must be of type \".ber\"\n");
		exit(0);
	}
}

int	close_window(void)
{
	exit(0);
	return (0);
}

bool	flood_fill(t_program *start, int x, int y)
{
	static int	found_exit = 0;
	static int	collected = 0;

	if (start->map_data[y][x] == '1')
		return (false);
	if (start->map_data[y][x] == 'E')
		found_exit = 1;
	if (start->map_data[y][x] == 'C')
		collected++;
	start->map_data[y][x] = '1';
	flood_fill(start, x + 1, y);
	flood_fill(start, x - 1, y);
	flood_fill(start, x, y + 1);
	flood_fill(start, x, y - 1);
	return (found_exit && collected == start->collectibles_count);
}

bool	check_valid_path(t_program *start)
{
	int	player_x;
	int	player_y;

	player_position(start);
	player_x = start->player_position_x;
	player_y = start->player_position_y;
	return (flood_fill(start, player_x, player_y));
}

int	main(int argc, char **argv)
{
	t_program	start;

	if (argc != 2)
	{
		arg_check(argc);
		return (0);
	}
	else
	{	
		ber_check(argv[1]);
		ft_memset(&start, 0, sizeof(start));
		start.mlx = mlx_init();
		open_map(argv[1], &start);
		map_size(&start);
		check_map(&start);
		path_check(&start);
		open_map(argv[1], &start);
		start.win = mlx_new_window(start.mlx, start.map_size_x * 60, \
		start.map_size_y * 60, "So Long");
		draw_map(&start);
		mlx_hooks(&start);
	}
	return (0);
}
