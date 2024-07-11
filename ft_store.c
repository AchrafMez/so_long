#include "so_long.h"

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

void ft_just_store(char *filename, t_map *mlx)
{
    int fd = open(filename, O_RDONLY);
    if(fd <= 0 || !filename)
        ft_error();
    int maplines = map_lines(fd, filename);
    close(fd);
    fd = open(filename, O_RDONLY);
    mlx->map = (char **)malloc(sizeof(char *) * (maplines + 1));
    if(!mlx->map)
        return ;
    char *line = get_next_line(fd);
    int line_len = 0;
    int i = 0;
    while(line)
    {
        line_len = ft_strlen(line);
        mlx->map[i]= ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    mlx->map[i] = NULL;
}
void  ft_store(char *filename, t_map *mlx)
{
    int fd = open(filename, O_RDONLY);
    if(fd <= 0 || !filename)
        ft_error();

    int maplines = map_lines(fd, filename);
    close(fd);
    fd = open(filename, O_RDONLY);
    mlx->map = (char **)malloc(sizeof(char *) * (maplines + 1));
    if(!mlx->map)
        return ;
    char *line = get_next_line(fd);
    int line_len = 0;
    int i = 0;
    while(line)
    {
        line_len = ft_strlen(line);
        mlx->map[i]= ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    mlx->map[i] = NULL;
    map_rectangular(mlx);
    ft_free(mlx->map, i);
    close(fd);
}
