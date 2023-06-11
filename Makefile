# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jciapova <jciapova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:17:38 by jciapova          #+#    #+#              #
#    Updated: 2023/06/11 17:23:55 by jciapova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBFT	= ./libft/libft.a
# LIBFT_DIR = ./libft

MINILIBX = ./mlx/libmlx.a
MINILIBX_DIR = ./mlx

CC	= cc -Wall -Wextra -Werror
RM	= rm -f

SRCSOLONG =	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
			so_long.c
NAME = so_long

all:	$(NAME)

# $(LIBFT):
#  	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) -g $(SRCSOLONG) $(MINILIBX) -lm -lXext -lX11 $(LIBFT) -o $(NAME)

clean:
	make clean -C $(MINILIBX_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all bonus