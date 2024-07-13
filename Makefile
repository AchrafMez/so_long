# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 00:01:46 by amezioun          #+#    #+#              #
#    Updated: 2024/07/14 00:01:47 by amezioun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./MLX42/include/MLX42 
SRCS = so_long.c  rectangular.c map_check.c treat.c loading.c keys.c exit.c flood_fill.c ft_store.c movements.c getnextline/get_next_line_utils.c getnextline/get_next_line.c ft_print/ft_print_format.c ft_print/ft_printf.c ft_print/ft_putchar.c ft_print/ft_putnbr_hexa.c ft_print/ft_putnbr.c ft_print/ft_putstr.c
MLX = ./MLX42/build/libmlx42.a -lglfw -L/Users/amezioun/.brew/opt/glfw/lib/ -framework Cocoa -framework OpenGL -framework IOKit
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJS) $(MLX)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re