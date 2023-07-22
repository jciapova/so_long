/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:33:18 by jciapova          #+#    #+#             */
/*   Updated: 2023/07/22 13:04:10 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_program *start)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (start->map_data[0][x] == '1' && \
	start->map_data[start->map_size_y - 1][x] == '1')
		x++;
	if (x != start->map_size_x)
		ft_printf("Error: Wrong map layout\n");
	while (start->map_data[y])
	{
		if (start->map_data[y][0] == '1' && \
		start->map_data[y][start->map_size_x - 1] == '1')
			i++;
		y++;
	}
	if (i != start->map_size_y)
	{
		ft_printf("Error: Wrong map layout\n");
		exit (0);
	}
}
