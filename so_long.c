#include <string.h>
#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"

void ft_error()
{
    write(2, "Error\n", 6);
    exit(1);
}

int map_lines(int fd, char *filename)
{
    int i = 0;
    char *line = get_next_line(fd);
    fd = open(filename, fd);
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return i;
}


void ft_free(char **map, int i)
{
    while(i--)
        free(map[i]);
    free(map);
}

int camp(char *filename)
{
    char *ext = ".ber";
    int i = ft_strlen(filename) - 4;
    while(filename[i])
    {
        if(filename[i] != *ext)
            return -1;
        ext++;
        i++;
    }
    return 0;
}

// void ft_copying(char *map, char *line)
// {
//     int i = 0;
//     if(!line)
//         return ;
//     while(line[i] != '\0')
//     {
//         map[i] = line[i];
//         i++;
//     }
//     map[i] = '\0';
//     free(line);
// }

// void  ft_store(char *filename)
// {
//     int fd = open(filename, O_RDONLY);
//     if(fd <= 0 || !filename)
//         ft_error();

//     int maplines = map_lines(fd, filename);
//     close(fd);
//     fd = open(filename, O_RDONLY);
//     char **map = (char **)malloc(sizeof(char *) * (maplines + 1));
//     if(!map)
//         return ;
//     char *line = get_next_line(fd);
//     int line_len = 0;
//     int i = 0;
//     while(line)
//     {
//         line_len = ft_strlen(line);
//         map[i]= strdup(line);
//         free(line);
//        line = get_next_line(fd);
//         i++;
//     }
//     map[i] = NULL;
//     map_rectangular(map);
//     ft_free(map, i);
//     close(fd);
// }


void  ft_store(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if(fd <= 0 || !filename)
        ft_error();

    int maplines = map_lines(fd, filename);
    close(fd);
    fd = open(filename, O_RDONLY);
    char **map = (char **)malloc(sizeof(char *) * (maplines + 1));
    if(!map)
        return ;
    char *line = get_next_line(fd);
    int line_len = 0;
    int i = 0;
    while(line)
    {
        line_len = ft_strlen(line);
        map[i]= ft_strdup(line);
        free(line);
       line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    map_rectangular(map);
    ft_free(map, i);
    close(fd);
}

int main(int ac, char **av)
{
    char *filename = av[1];
    int fd = open(filename, O_RDONLY);
    if(ac != 2)
        ft_error();
    else
    {
        if(camp(filename) == -1)
        {
            printf("filename error\n");
            return 1;
        }
        else
            ft_store(filename);
            // map_rectangular(fd, filename);
    }
    close(fd);
    mlx_t *mlx;
    // int a = 0;
    // void *new_window;
    mlx = mlx_init(800, 800, "so_long", true);
    
    mlx_new_window(mlx, 800, 800, "so_long");
    mlx_loop(mlx);
    // system("leaks so_long");
}
