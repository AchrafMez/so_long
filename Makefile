NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
# -fsanitize=address -g
SRCS = libc_utils.c so_long.c getnextline/get_next_line_utils.c getnextline/get_next_line.c ractangular.c
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re