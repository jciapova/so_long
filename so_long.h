/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:08:13 by jciapova          #+#    #+#             */
/*   Updated: 2023/06/11 18:47:47 by jciapova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include "get_next_line/get_next_line.h"

# define WALL "./tree.xpm"

typedef struct  s_program
{
    void    *mlx;
    void    *win;
    void    *img;
    char    **map_data;
    int     img_height;
    int     img_width;
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