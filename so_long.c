#include <string.h>
#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>

void ft_error_free(t_map *mlx)
{
    int i = 0;

    while(mlx->map[i] != NULL)
    {
        free(mlx->map[i]);
        i++;
    }
    free(mlx->map);
}
void ft_error(t_map *mlx)
{
    write(2, "Error adsf\n", 11);
    ft_error_free(mlx);
    // printf("mlx y -> %d\n", mlx->y);
    // ft_free(mlx->map, mlx->y);
    exit(1);
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

void test()
{
    system("leaks so_long");
}

void ft_put_floor(t_map *mlx)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(mlx->map[y])
    {
        while(mlx->map[y][x])
        {
            mlx_image_to_window(mlx->mlx, mlx->img[0], x * 32, y * 32);
            x++;
        }
        x = 0;
        y++;
    }
}

void delete_texture(t_map *mlx)
{
    int i;

    i = 4;
    while(i >= 0)
    {
        mlx_delete_texture(mlx->texture[i]);
        i--;
    }
}
void key_press(struct mlx_key_data key_data, void *param)
{
    t_map *mlx = (t_map *)param;
    if(((key_data.key == MLX_KEY_UP) || key_data.key == MLX_KEY_W) && key_data.action)
        move_up(mlx);
    else if((key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S) && key_data.action)
        move_down(mlx);
    else if((key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D) && key_data.action)
        move_right(mlx);
    else if((key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A) && key_data.action)
        move_left(mlx);
    else if(key_data.key == MLX_KEY_ESCAPE)
    {
        if(mlx->mlx != NULL){
            mlx_close_window(mlx->mlx);
            mlx->mlx = NULL;
        }
    }
}
void load_png(t_map *mlx)
{
    mlx->texture[0] = mlx_load_png("./solong_assists/floor.png"); //flor
    mlx->texture[1] = mlx_load_png("./solong_assists/wall.png"); //wall
    mlx->texture[2] = mlx_load_png("./solong_assists/player.png"); //player
    mlx->texture[3] = mlx_load_png("./solong_assists/03.png"); //coin
    mlx->texture[4] = mlx_load_png("./solong_assists/exit.png"); //exit
}

void png_to_image(t_map *mlx)
{
    mlx->img[0] = mlx_texture_to_image(mlx->mlx, mlx->texture[0]);
    mlx->img[1] = mlx_texture_to_image(mlx->mlx, mlx->texture[1]);
    mlx->img[2] = mlx_texture_to_image(mlx->mlx, mlx->texture[2]);
    mlx->img[3] = mlx_texture_to_image(mlx->mlx, mlx->texture[3]);
    mlx->img[4] = mlx_texture_to_image(mlx->mlx, mlx->texture[4]);
}

void put_pictures(t_map *mlx)
{
    int y = 0;
    int x = 0;
    while(mlx->map[y])
    {
        while(mlx->map[y][x])
        {
            if(mlx->map[y][x] == 'E')
                mlx_image_to_window(mlx->mlx, mlx->img[4], x * 32, y * 32);
            else if(mlx->map[y][x] == '0')
                mlx_image_to_window(mlx->mlx, mlx->img[0], x * 32, y * 32);
            else if(mlx->map[y][x] == '1')
                mlx_image_to_window(mlx->mlx, mlx->img[1], x * 32, y * 32);
            else if(mlx->map[y][x] == 'P')
                mlx_image_to_window(mlx->mlx, mlx->img[2], x * 32, y * 32);
            else if(mlx->map[y][x] == 'C')
                mlx_image_to_window(mlx->mlx, mlx->img[3], x * 32, y * 32);
            x++;
        }
        x = 0;
        y++;
    }
}
void treat(char *filename, t_map *mlx)
{
    int fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        write(2, "Invalid map !\n", 14);
        exit(1);
    }
    else
    {
        ft_store(filename, mlx);
        player_check(mlx->map);
        if(check_path(mlx->map) == 1)
        {
            ft_free(mlx->map, mlx->y);
            write(2, "Error: the map provided does not have a valid path\n", 52);
            exit(1);
        }
            ft_free(mlx->map, mlx->y);
            ft_store(filename, mlx);
    }
    close(fd);
}

int main(int ac, char **av)
{
    atexit(test);
    if(ac != 2)
    {
        write(2, "Arguments Error\n", 17);
        return 1;
    }
    t_map mlx;
    char *filename = av[1];
    if(camp(filename) == -1)
           ft_error(&mlx);
    treat(filename, &mlx);
    load_png(&mlx);
    mlx.WIDTH = mlx.x * 32;
    mlx.HEIGHT = mlx.y * 32;
    mlx.mlx = mlx_init(mlx.WIDTH, mlx.HEIGHT, "so_long", false);
    png_to_image(&mlx);
    ft_put_floor(&mlx);
    get_e(&mlx);
    put_pictures(&mlx);
    mlx_key_hook(mlx.mlx, key_press, &mlx);
    mlx_loop(mlx.mlx);
    ft_free(mlx.map, mlx.y);
    delete_texture(&mlx);
}
