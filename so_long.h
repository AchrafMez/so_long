#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include "printf/ft_printf.h"
#include "getnextline/get_next_line.h"
#include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_map{
    char **map;
    mlx_t *mlx;
    mlx_image_t *img[5];
    mlx_texture_t *texture[5];
    int player_y;
    int player_x;
    int player;
    int coins;
    int exit;
} t_map;

void player_check(char **map);
void map_rectangular(t_map *mlx);
void flood_fill(char **map, int y, int x);
void ft_error();
char **ft_split(char *str, char c);
int check_path(char **map);

#endif