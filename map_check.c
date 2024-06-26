#include "so_long.h"

int check(char **map)
{
    int x = 0;
    int y = 0;
    while(map[y])
    {
        if(map[y][x] != 'C' || map[y][x] != 'E' || map[y][x] != 'P' || map[y][x] || map[y][x] != '1' || map[y][x] != '0' || map[y][x] != '\n')
        {
            printf("map character erro\n");
            return 1;
        }
    }
    return 0;
}
