#include <string.h>
#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

void player_check(char **map)
{
    int x = 0;
    int y = 0;
    while(map[y][x])
    {
        while(map[y][x])
        {
            if(map[y][x] == 'P')
            {
                printf("%d %d\n", y, x);
                flood_fill(map, y, x);
                return ;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void flood_fill(char **map, int y, int x)
{
    if(map[y][x] == '*' || map[y][x] == '1')
        return ;
    map[y][x] = '*';
    flood_fill(map, y - 1, x);
    flood_fill(map, y + 1, x);
    flood_fill(map, y, x - 1);
    flood_fill(map, y, x + 1);
}

int check_path(char **map)
{
    int y = 0; 
    int x = 0;
    while(map[y])
    {
        while(map[y][x])
        {
            if(map[y][x] == 'C' || map[y][x] == 'E')
                return 1;
            x++;
        }
        x = 0;
        y++;
    }
    return 0;
}