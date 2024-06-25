#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include "printf/ft_printf.h"
#include "getnextline/get_next_line.h"

typedef struct s_map{
    int player;
    int coins;
    int exit;
    int lines;

} t_map;

void map_rectangular(char **map);
void ft_error();
char **ft_split(char *str, char c);


#endif