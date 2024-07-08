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
void test()
{
    system("leaks so_long");
}

void ft_put_floor(t_map *mlx)
{
    int x = 0;
    int y = 0;
    while(mlx->map[y])
    {
        while(mlx->map[y][x])
        {
            mlx_image_to_window(mlx->mlx, mlx->img[0], y * 32, x * 32);
            x++;
        }
        x = 0;
        y++;
    }
}

void key_press(struct mlx_key_data key_data, void *param)
{
    (void)param;
    if(key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_W)
        printf("up\n");
    else if(key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S)
        printf("DOWN\n");
    else if(key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D)
        printf("RIGHT\n");
    else if(key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A)
        printf("LEFT\n");
    // else if(key_data.key == MLX_KEY_ESCAPE)
        // mlx_close_window();
}
int main(int ac, char **av)
{
    t_map mlx;
    // atexit(test);
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
        {

            ft_store(filename, &mlx);
            ft_just_store(filename, &mlx);
        }
            // printf("exit -> %d\n", mlx.);
            // map_rectangular(fd, filename);
    }
    close(fd);
    // printf("player x -> %d\n", mlx.player_x);
    // printf("player y -> %d\n", mlx.player_y);
    // printf("player -> %d\n", mlx.player);
    // printf("coins -> %d\n", mlx.coins);
    // printf("exit -> %d\n", mlx.exit);
    // int a = 0;
    // void *new_window;
    mlx.texture[0] = mlx_load_png("./solong_assists/floor.png"); //flor
    mlx.texture[1] = mlx_load_png("./solong_assists/wall.png"); //wall
    mlx.texture[2] = mlx_load_png("./solong_assists/player.png"); //player
    mlx.texture[3] = mlx_load_png("./solong_assists/03.png"); //coin
    mlx.texture[4] = mlx_load_png("./solong_assists/exit.png"); //exit

    mlx.mlx = mlx_init(800, 800, "so_long", true);
    mlx.img[0] = mlx_texture_to_image(mlx.mlx, mlx.texture[0]);
    mlx.img[1] = mlx_texture_to_image(mlx.mlx, mlx.texture[1]);
    mlx.img[2] = mlx_texture_to_image(mlx.mlx, mlx.texture[2]);
    mlx.img[3] = mlx_texture_to_image(mlx.mlx, mlx.texture[3]);
    mlx.img[4] = mlx_texture_to_image(mlx.mlx, mlx.texture[4]);
    int y = 0;
    int x = 0;
    ft_put_floor(&mlx);
    while(mlx.map[y])
    {
        while(mlx.map[y][x])
        {
            // if(mlx.map[y][x] == '0')
            //     mlx_image_to_window(mlx.mlx, mlx.img[0], y * 32, x * 32);
            if(mlx.map[y][x] == '1')
                mlx_image_to_window(mlx.mlx, mlx.img[1], y * 32, x * 32);
            if(mlx.map[y][x] == 'P')
                mlx_image_to_window(mlx.mlx, mlx.img[2], y * 32, x * 32);
            if(mlx.map[y][x] == 'C')
                mlx_image_to_window(mlx.mlx, mlx.img[3], y * 32, x * 32);
            if(mlx.map[y][x] == 'E')
                mlx_image_to_window(mlx.mlx, mlx.img[4], y * 32, x * 32);
            // mlx_image_to_window(mlx.mlx, mlx.img[1], 0, 1 *32);
            x++;
        }
        x = 0;
        y++;

    }
    mlx_key_hook(mlx.mlx, key_press, NULL);
    // mlx_new_window(mlx, 800, 800, "so_long");
    mlx_loop(mlx.mlx);
    
    // system("leaks so_long");
}
