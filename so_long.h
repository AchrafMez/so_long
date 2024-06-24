#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include "printf/ft_printf.h"
#include "getnextline/get_next_line.h"

typedef struct s_map{
    // int player;
    // int collect;
    char **map;
    char *line;
} t_map;

char **ft_split(char *str, char c);


#endif