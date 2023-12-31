# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:17:38 by jciapova          #+#    #+#              #
#    Updated: 2023/07/22 14:46:48 by jciapova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ./libft/libft.a
LIBFT_DIR = ./libft

MINILIBX = ./mlx/libmlx.a
MINILIBX_DIR = ./mlx

PRINTF	= ./printf/libftprintf.a
PRINTF_DIR = ./printf

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCSOLONG =	./get_next_line/get_next_line.c \
			./src/so_long.c ./src/player_moves.c ./src/player_position.c ./src/map.c ./src/check_map.c \
			./src/check_map_plus.c ./src/init_map.c
NAME = so_long

all:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(PRINTF)
	$(CC) -g $(SRCSOLONG) $(MINILIBX) -lXext -lX11 -lm $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(NAME) $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	make clean -C $(PRINTF_DIR)

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re:	fclean all
