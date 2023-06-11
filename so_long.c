/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:34 by jciapova          #+#    #+#             */
/*   Updated: 2023/06/11 18:47:41 by jciapova         ###   ########.fr       */
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

void	draw_map(t_program *start)
{
	int			y;
	int			x;
	
	y = 0;
	start->img = mlx_xpm_file_to_image(start->mlx, WALL, &start->img_width, &start->img_height);
	while (start->map_data[y])
	{
		x = 0;
		printf("Hello");
		while (start->map_data[y][x])
		{
			if (start->map_data[y][x] == '1')
				mlx_put_image_to_window(start->mlx, start->win, start->img, y*40, x*40);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_program	start;
	int		fd;
	char		*line;
	char		*all_lines;
	char		*temp;

	if (argc != 2)
		return (0);
	start.mlx = mlx_init();
	start.win = mlx_new_window(start.mlx, 600, 600, "So Long");
	
	fd = open(argv[1], O_RDONLY);
	all_lines = "";
	while (1)
	{
		line = get_next_line(fd);
		temp = all_lines;
		all_lines = ft_strjoin(temp, line);
		free(line);
	}
	close(fd);
	start.map_data = ft_split(all_lines, '\n');
	free(all_lines);
	draw_map(&start);
	mlx_loop(start.mlx);
	return (0);
}