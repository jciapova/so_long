/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:40:32 by jciapova          #+#    #+#             */
/*   Updated: 2023/07/22 14:05:42 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(int argc)
{
	if (argc < 2)
		ft_printf("Error: You forgot to include something.\n");
	if (argc > 2)
		ft_printf("You can only include one map.\n");
}

void	mlx_hooks(t_program *start)
{
	mlx_hook(start->win, 2, 1L << 0, move_player, start);
	mlx_hook(start->win, 17, 1L << 2, close_window, start);
	mlx_loop(start->mlx);
}

void	path_check(t_program *start)
{
	if (!check_valid_path(start))
	{
		ft_printf("Error: No valid path.\n");
		exit(0);
	}
}
