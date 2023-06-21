/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:08:13 by jciapova          #+#    #+#             */
/*   Updated: 2023/06/21 18:19:27 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include "get_next_line/get_next_line.h"

# define WALL "./assets/tree.xpm"
# define PLAYER "./assets/player1.xpm"
# define COLLECTIBLE "./assets/dragon.xpm"
# define EXIT "./assets/gate.xpm"
# define TILE "./assets/grass.xpm"

typedef struct  s_program
{
    void    *mlx;
    void    *win;
    void    *img_wall;
    void    *img_player;
    void    *img_collectible;
    void    *img_exit;
    void    *img_tile;
    char    **map_data;
    int     img_height;
    int     img_width;
    int     map_size_x;
    int     map_size_y;
    int     player_position_x;
    int     player_position_y;
}   	t_program;

typedef struct	s_game_map
{
    int		map_height;
    int		map_length;
    int 	player_position_x;
    int		player_position_y;
    int		steps;
    void	*wall;
    void	*exit;
    void	*player;
}	t_game_map;

#endif