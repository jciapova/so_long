/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:08:13 by jciapova          #+#    #+#             */
/*   Updated: 2023/07/22 14:43:50 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include "../printf/ft_printf.h"
# include <stdbool.h>

# define WALL "./assets/tree.xpm"
# define PLAYER "./assets/player1.xpm"
# define COLLECTIBLE "./assets/dragon.xpm"
# define EXIT "./assets/gate.xpm"
# define TILE "./assets/grass.xpm"

typedef struct s_program
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	void	*img_tile;
	char	**map_data;
	int		img_height;
	int		img_width;
	int		map_size_x;
	int		map_size_y;
	int		player_position_x;
	int		player_position_y;
	int		moves_count;
	int		collected;
	int		collectibles_count;
	int		player_count;
	int		exit_count;
}	t_program;

int		move_player(int key, t_program *start);
int		close_window(void);
void	move_w(t_program *start, int x, int y);
void	move_a(t_program *start, int x, int y);
void	move_s(t_program *start, int x, int y);
void	move_d(t_program *start, int x, int y);
void	player_position(t_program *start);
void	new_player_position(t_program *start, char key);
void	new_player_position_w_s(t_program *start, char key, int x, int y);
void	put_images(t_program *start, int x, int y);
void	draw_map(t_program *start);
void	open_map(char *argv, t_program *start);
void	map_size(t_program *start);
void	check_collectibles(t_program *start);
void	check_player(t_program *start);
void	check_exit(t_program *start);
void	check_map(t_program *start);
void	check_if_empty(t_program *start);
void	put_images_extra(t_program *start, int x, int y);
void	check_walls(t_program *start);
void	mlx_hooks(t_program *start);
void	arg_check(int argc);
void	path_check(t_program *start);
bool	check_valid_path(t_program *start);
bool	flood_fill(t_program *start, int x, int y);
void	ber_check(char *argv);

#endif