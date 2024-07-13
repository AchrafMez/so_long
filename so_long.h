/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:03:21 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 03:39:25 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int x;
    int y;
    int exit_y;
    int exit_x;
    int player_y;
    int player_x;
    int player;
    int coins;
    int exit;
} t_map;

//flood fill
void flood_fill(char **map, int y, int x);
int check_path(char **map);

void player_check(char **map);
void ft_error();
int check_path(char **map);

//rectangular
void ones_line(char *line);
int map_check(t_map *mlx);
int check(char *line);
int map_len(t_map *mlx);
int map_rectangular(t_map *mlx);


void ft_free(char **map, int i);
void  ft_store(char *filename, t_map *mlx);
int camp(char *filename);

//ft_store
void ft_just_store(char *filename, t_map *mlx);
int map_lines(int fd, char *filename);

//movements
void move_up(t_map *mlx);
void move_down(t_map *mlx);
void move_right(t_map *mlx);
void move_left(t_map *mlx);
void get_e(t_map *mlx);
#endif