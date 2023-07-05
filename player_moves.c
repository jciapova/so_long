/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janka <janka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:42:19 by janka             #+#    #+#             */
/*   Updated: 2023/07/05 13:33:22 by janka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void   move_w(t_program *start)
{
	mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
	mlx_put_image_to_window(start->mlx, start->win, start->img_player, start->player_position_x * 60, (start->player_position_y - 1) * 60);
	new_player_position(start, 'w');
	start->moves_count++;
	ft_printf("Moves: %d\n", start->moves_count);
} 

void	move_s(t_program *start)
{
	mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
	mlx_put_image_to_window(start->mlx, start->win, start->img_player, start->player_position_x * 60, (start->player_position_y + 1) * 60);
	new_player_position(start, 's');
	start->moves_count++;
	ft_printf("Moves: %d\n", start->moves_count);
}

void	move_a(t_program *start)
{
	mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
	mlx_put_image_to_window(start->mlx, start->win, start->img_player, (start->player_position_x - 1) * 60, start->player_position_y * 60);
	new_player_position(start, 'a');
	start->moves_count++;
	ft_printf("Moves: %d\n", start->moves_count);
}

void	move_d(t_program *start)
{
	mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
	mlx_put_image_to_window(start->mlx, start->win, start->img_player, (start->player_position_x + 1) * 60, start->player_position_y * 60);
	new_player_position(start, 'd');
	start->moves_count++;
	ft_printf("Moves: %d\n", start->moves_count);
}

int	move_player(int key, t_program *start)
{
	int x;
	int y;
	
	player_position(start);
	x = start->player_position_x;
	y = start->player_position_y;
	if (key == 65307)
	{
		mlx_destroy_window(start->mlx, start->win);
		exit(0);
	}
	if (key == 'w' && start->map_data[y - 1][x] != '1')
		move_w(start);
	if (key == 's' && start->map_data[y + 1][x] != '1')
		move_s(start);
	if (key == 'a' && start->map_data[y][x - 1] != '1')
		move_a(start);
	if (key == 'd' && start->map_data[y][x + 1] != '1')
		move_d(start);
	return(0);
}