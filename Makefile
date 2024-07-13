NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./MLX42/include/MLX42 
#-fsanitize=address -g
SRCS = so_long.c getnextline/get_next_line_utils.c getnextline/get_next_line.c ractangular.c flood_fill.c movements.c ft_store.c
MLX = ./MLX42/build/libmlx42.a -lglfw 
# -framework Cocoa -framework OpenGL -framework IOKit
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o  $(NAME) $(OBJS) $(MLX) ./MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re