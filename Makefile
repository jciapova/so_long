# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janka <janka@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:17:38 by jciapova          #+#    #+#              #
#    Updated: 2023/07/05 13:10:02 by janka            ###   ########.fr        #
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
			so_long.c player_moves.c player_position.c map.c
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
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re:	fclean all bonus

re:	fclean all
