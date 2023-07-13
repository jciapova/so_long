/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:54:19 by janka             #+#    #+#             */
/*   Updated: 2023/07/13 20:06:00 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_program *start)
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
			{
				start->player_position_x = x;
				start->player_position_y = y;
			}
			x++;
		}
		y++;
	}
}

void	new_player_position_w_s(t_program *start, char key, int x, int y)
{
	char	update;

	if (key == 'w' && start->map_data[y - 1][x] != '1')
	{
		update = start->map_data[y][x];
		start->map_data[y][x] = start->map_data[y - 1][x];
		start->map_data[y - 1][x] = update;
	}
	if (key == 's' && start->map_data[y + 1][x] != '1')
	{
		update = start->map_data[y][x];
		start->map_data[y][x] = start->map_data[y + 1][x];
		start->map_data[y + 1][x] = update;
	}
}

void	new_player_position(t_program *start, char key)
{
	int		x;
	int		y;
	char	update;

	x = start->player_position_x;
	y = start->player_position_y;
	new_player_position_w_s(start, key, x, y);
	if (key == 'a' && start->map_data[y][x - 1] != '1')
	{
		update = start->map_data[y][x];
		start->map_data[y][x] = start->map_data[y][x - 1];
		start->map_data[y][x - 1] = update;
	}
	if (key == 'd' && start->map_data[y][x + 1] != '1')
	{
		update = start->map_data[y][x];
		start->map_data[y][x] = start->map_data[y][x + 1];
		start->map_data[y][x + 1] = update;
	}
}
