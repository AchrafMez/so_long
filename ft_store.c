#include "so_long.h"

int map_lines(int fd, char *filename)
{
    int i = 0;
    char *line = NULL;
    fd = open(filename, fd);
    while((line = get_next_line(fd)) != NULL)
    {
        free(line);
        i++;
        printf("i ->%d\n", i);
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
    fd = open(filename, O_RDONLY);
    mlx->map = (char **)malloc(sizeof(char *) * (maplines));
    if(!mlx->map)
        return ;
    char *line = get_next_line(fd);
    int i = 0;
    while(line)
    {
        mlx->map[i]= ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    mlx->map[i] = NULL;
}
void  ft_store(char *filename, t_map *mlx)
{
    // int fd = open(filename, O_RDONLY);
    // if(fd <= 0 || !filename)
        // ft_error();
    // close(fd);
    int fd = open(filename, O_RDONLY);
    int maplines = map_lines(fd, filename);
    printf("line count: %d\n", maplines);
    mlx->map = (char **)malloc(sizeof(char *) * (maplines + 1));
    if(!mlx->map)
        return ;
    char *line = get_next_line(fd);
    // int line_len = 0;
    int i = 0;
    while(line)
    {
        // line_len = ft_strlen(line);
        mlx->map[i]= line;
        line = get_next_line(fd);
        i++;
        // free(line);
    }
    // free(line);
    mlx->map[i] = NULL;
    map_rectangular(mlx);
    close(fd);
}
