/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janka <janka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:07:36 by janka             #+#    #+#             */
/*   Updated: 2023/07/05 13:11:28 by janka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	put_images(t_program *start, int x, int y)
{
	start->img_wall = mlx_xpm_file_to_image(start->mlx, WALL, &start->img_width, &start->img_height);
	start->img_player = mlx_xpm_file_to_image(start->mlx, PLAYER, &start->img_width, &start->img_height);
	start->img_collectible = mlx_xpm_file_to_image(start->mlx, COLLECTIBLE, &start->img_width, &start->img_height);
	start->img_exit = mlx_xpm_file_to_image(start->mlx, EXIT, &start->img_width, &start->img_height);
	start->img_tile = mlx_xpm_file_to_image(start->mlx, TILE, &start->img_width, &start->img_height);
	
	while (start->map_data[y][x])
	{
		mlx_put_image_to_window(start->mlx, start->win, start->img_tile, x*60, y*60);
		if (start->map_data[y][x] == '1')
			mlx_put_image_to_window(start->mlx, start->win, start->img_wall, x*60, y*60);
		else if (start->map_data[y][x] == 'P')
			mlx_put_image_to_window(start->mlx, start->win, start->img_player, x*60, y*60);
		else if (start->map_data[y][x] == 'C')
			mlx_put_image_to_window(start->mlx, start->win, start->img_collectible, x*60, y*60);
		else if (start->map_data[y][x] == 'E')
			mlx_put_image_to_window(start->mlx, start->win, start->img_exit, x*60, y*60);
		x++;
	}
}

void	draw_map(t_program *start)
{
	int			y;
	int			x;
	y = 0;
	while (start->map_data[y])
	{
		x = 0;
		put_images(start, x, y);
		y++;
	}
}

void	start_map(char *argv, t_program *start)
{
	int		fd;
	char		*line;
	char		*all_lines;
	char		*temp;

	fd = open(argv, O_RDONLY);
	all_lines = "";
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
	}
	close(fd);
	start->map_data = ft_split(all_lines, '\n');
	free(all_lines);	
}

void	map_size(t_program *start)
{
	int	i;
	
	start->map_size_x = 0;
	start->map_size_y = 0;
	i = 0;
	while (start->map_data[0][i])
	{
		start->map_size_x++;
		i++;
	}
	i = 0;
	while (start->map_data[i])
	{
		start->map_size_y++;
		i++;
	}

}