/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:52:11 by janka             #+#    #+#             */
/*   Updated: 2023/07/13 20:31:56 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectibles(t_program *start)
{
	int	x;
	int	y;

	start->collectibles_count = 0;
	y = 0;
	while (start->map_data[y])
	{
		x = 0;
		while (start->map_data[y][x])
		{
			if (start->map_data[y][x] == 'C')
				start->collectibles_count++;
			x++;
		}
		y++;
	}
	if (start->collectibles_count == 0)
	{
		ft_printf("Error: No collectibles found\n");
		exit(0);
	}
}

void	check_player(t_program *start)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (start->map_data[y])
	{
		x = 0;
		while (start->map_data[y][x])
		{
			if (start->map_data[y][x] == 'P')
				start->player_count++;
			x++;
		}
		y++;
	}
	if (start->player_count != 1)
	{
		ft_printf("Error: Game can only have 1 player\n");
		exit(0);
	}
}

void	check_exit(t_program *start)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (start->map_data[y])
	{
		x = 0;
		while (start->map_data[y][x])
		{
			if (start->map_data[y][x] == 'E')
				start->exit_count++;
			x++;
		}
		y++;
	}
	if (start->exit_count != 1)
	{
		ft_printf("Error: There can only be 1 exit\n");
		exit(0);
	}
}

void	check_if_empty(t_program *start)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (start->map_data[y])
	{
		x = 0;
		while (start->map_data[y][x])
		{
			if (start->map_data[y][x] != 'E' && start->map_data[y][x] != 'P' && \
			start->map_data[y][x] != '0' && start->map_data[y][x] != 'C' && \
			start->map_data[y][x] != '1')
			{
				ft_printf("Error: Map is empty\n");
				exit(0);
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_program *start)
{
	check_if_empty(start);
	check_player(start);
	check_collectibles(start);
	check_exit(start);
	check_walls(start);
}

