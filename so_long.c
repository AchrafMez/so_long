#include <string.h>
#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>

void ft_error()
{
    write(2, "Error\n", 6);
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
            mlx_image_to_window(mlx->mlx, mlx->img[0], x * 32, y * 32);
            x++;
        }
        x = 0;
        y++;
    }
}


void key_press(struct mlx_key_data key_data, void *param)
{
    t_map *mlx = (t_map *)param;
    if(((key_data.key == MLX_KEY_UP) || key_data.key == MLX_KEY_W) && key_data.action)
    {
        move_up(mlx);
        printf("up\n");
    }
    else if((key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S) && key_data.action)
    {
        move_down(mlx);
        printf("DOWN\n");
    }
    else if((key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D) && key_data.action)
    {
        move_right(mlx);
        printf("RIGHT\n");
    }
    else if((key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A) && key_data.action)
    {
        move_left(mlx);
        printf("LEFT\n");
    }
    else if(key_data.key == MLX_KEY_ESCAPE)
    {
        printf("destrory");
        mlx_close_window(mlx->mlx);
        // ft_free(mlx.map, 25);
        // exit(1);
    }
    printf("coins -> %d\n", mlx->coins);
}
int main(int ac, char **av)
{
    t_map mlx;
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
            int j = 0;
            ft_store(filename, &mlx);
            // ft_just_store(filename, &mlx);
            printf("x -> %d\n", mlx.x);
            printf("y -> %d\n", mlx.y);
            player_check(mlx.map);
            if(check_path(mlx.map) == 1)
            {
                ft_free(mlx.map, mlx.y);
                printf("Error: the map provided doesnt have a valid path");
                exit(1);
            }
            while(mlx.map[j])
            {
                printf("[main]: line: %s\n", mlx.map[j]);
                j++;
            }
            // ft_free(mlx.map, mlx.y);
            // j = 0;
            // while(mlx.map[j])
            // {
            //     printf("%s\n", mlx.map[j]);
            //     j++;
            // }

            ft_store(filename, &mlx);
            // ft_just_store(filename, &mlx);
                
            }
            // printf("exit -> %d\n", mlx.);
            // map_rectangular(fd, filename);
    }
    close(fd);
    mlx.texture[0] = mlx_load_png("./solong_assists/floor.png"); //flor
    mlx.texture[1] = mlx_load_png("./solong_assists/wall.png"); //wall
    mlx.texture[2] = mlx_load_png("./solong_assists/player.png"); //player
    mlx.texture[3] = mlx_load_png("./solong_assists/03.png"); //coin
    mlx.texture[4] = mlx_load_png("./solong_assists/exit.png"); //exit
    int WIDTH = mlx.x * 32;
    int HEIGHT = mlx.y * 32;
    mlx.mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
    mlx.img[0] = mlx_texture_to_image(mlx.mlx, mlx.texture[0]);
    mlx.img[1] = mlx_texture_to_image(mlx.mlx, mlx.texture[1]);
    mlx.img[2] = mlx_texture_to_image(mlx.mlx, mlx.texture[2]);
    mlx.img[3] = mlx_texture_to_image(mlx.mlx, mlx.texture[3]);
    mlx.img[4] = mlx_texture_to_image(mlx.mlx, mlx.texture[4]);
    int y = 0;
    int x = 0;
    int k = 0;
            while(mlx.map[k])
            {
                printf("map before put floor -> %s\n", mlx.map[k]);
                k++;
            }
    ft_put_floor(&mlx);
    // struct mlx_key_data key_data;
    while(mlx.map[y])
    {
        while(mlx.map[y][x])
        {
            if(mlx.map[y][x] == '0')
                mlx_image_to_window(mlx.mlx, mlx.img[0], x * 32, y * 32);
            else if(mlx.map[y][x] == '1')
                mlx_image_to_window(mlx.mlx, mlx.img[1], x * 32, y * 32);
            else if(mlx.map[y][x] == 'P')
                mlx_image_to_window(mlx.mlx, mlx.img[2], x * 32, y * 32);
            else if(mlx.map[y][x] == 'C')
                mlx_image_to_window(mlx.mlx, mlx.img[3], x * 32, y * 32);
            else if(mlx.map[y][x] == 'E')
                mlx_image_to_window(mlx.mlx, mlx.img[4], x * 32, y * 32);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_key_hook(mlx.mlx, key_press, &mlx);
    // if(key_data.key == MLX_KEY_ESCAPE)
    // {
        // printf("destroy");
        // mlx_c lose_window(mlx.mlx);
    // }
    // mlx_new_window(mlx, 800, 800, "so_long");
    mlx_loop(mlx.mlx);
    ft_free(mlx.map, y);
    // atexit(test);
    // system("leaks so_long");
}
