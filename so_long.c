/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:34 by jciapova          #+#    #+#             */
/*   Updated: 2023/06/22 22:34:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>

int	count(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

int	trim_loop(const char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

char	**write_array(const char *s, char c, char **str, int words)
{
	int	i;
	int	j;
	int	next;

	i = 0;
	next = 0;
	while (s[i] != '\0' && next < words)
	{
		j = 0;
		if (s[i] == c)
			i = trim_loop(s, c, i);
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		str[next] = (char *)malloc(sizeof(char) * (j + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str[next], &s[i - j], (j + 1));
		next++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	words = count(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str[words] = NULL;
	str = write_array(s, c, str, words);
	return (str);
}

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

// void	new_player_position_w_s(t_program *start, char key, int x, int y)
// {
// 	char	update;

// 	if (key == 'w' && start->map_data[y - 1][x] != '1')
// 	{
// 		update = start->map_data[y][x];
// 		start->map_data[y][x] = start->map_data[y - 1][x];
// 		start->map_data[y - 1][x] = update;
// 	}
// 	if (key == 's' && start->map_data[y + 1][x] != '1')
// 	{
// 		update = start->map_data[y][x];
// 		start->map_data[y][x] = start->map_data[y + 1][x];
// 		start->map_data[y + 1][x] = update;
// 	}
// }

void	new_player_position(t_program *start, char key)
{
	int	x;
	int	y;
	char	update;

	x = start->player_position_x;
	y = start->player_position_y;
	//new_player_position_w_s(start, key, x, y);
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

int	move_player(int key, t_program *start)
{
	int x;
	int y;

	player_position(start);
	x = start->player_position_x;
	y = start->player_position_y;
	printf("%d\n", start->player_position_x);
	printf("%d\n", start->player_position_y);
	if (key == 65307)
		mlx_destroy_window(start->mlx, start->win);
	if (key == 'w' && start->map_data[y - 1][x] != '1')
	{
		//player_position(start);
		mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
		mlx_put_image_to_window(start->mlx, start->win, start->img_player, start->player_position_x * 60, (start->player_position_y - 1) * 60);
		new_player_position(start, 'w');
	}
	if (key == 's' && start->map_data[y + 1][x] != '1')
	{
		//player_position(start);
		mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
		mlx_put_image_to_window(start->mlx, start->win, start->img_player, start->player_position_x * 60, (start->player_position_y + 1) * 60);
		new_player_position(start, 's');
	}
	if (key == 'a' && start->map_data[y][x - 1] != '1')
	{
		//player_position(start);
		mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
		mlx_put_image_to_window(start->mlx, start->win, start->img_player, (start->player_position_x - 1) * 60, start->player_position_y * 60);
		new_player_position(start, 'a');
	}
	if (key == 'd' && start->map_data[y][x + 1] != '1')
	{
		//player_position(start);
		mlx_put_image_to_window(start->mlx, start->win, start->img_tile, start->player_position_x * 60, start->player_position_y * 60);
		mlx_put_image_to_window(start->mlx, start->win, start->img_player, (start->player_position_x + 1) * 60, start->player_position_y * 60);
		new_player_position(start, 'd');
	}
	return(0);
}

int	main(int argc, char **argv)
{
	t_program	start;
	
	if (argc != 2)
		return (0);
	else
	{
		start.mlx = mlx_init();
		start_map(argv[1], &start);
		map_size(&start);
		start.win = mlx_new_window(start.mlx, start.map_size_x * 60, start.map_size_y * 60, "So Long");
		draw_map(&start);
		mlx_hook(start.win, 2, 1L<<0, move_player, &start);
		mlx_loop(start.mlx);
	}
	return (0);
}