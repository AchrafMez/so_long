/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:16:42 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/12 18:07:20 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_map *mlx)
{
    printf("%d\n", mlx->player_y);
    if(mlx->map[mlx->player_y - 1][mlx->player_x] != '1' && mlx->map[mlx->player_y - 1][mlx->player_x] != '1')
    {
        if(mlx->map[mlx->player_y - 1][mlx->player_x] == 'C')
        {
            mlx->map[mlx->player_y - 1][mlx->player_x] = '0';
            mlx->coins--;
        }
        mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x *32, mlx->player_y * 32);
        mlx->player_y--;
        mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32, mlx->player_y * 32);
    }
    else if(mlx->map[mlx->player_y - 1][mlx->player_x] == 'E')
    {
        mlx->map[mlx->player_y + 1][mlx->player_x] = 'E';
        printf("y:  x:%d %d\n", mlx->player_y, mlx->player_x);
        mlx_image_to_window(mlx->mlx, mlx->img[4], mlx->player_x *32, mlx->player_y * 32);
        mlx->player_y--;
    }
    else if(mlx->coins == 0 && mlx->map[mlx->player_y - 1][mlx->player_x] == 'E')
    {
        printf("Yo hoo You Win !");
        mlx_close_window(mlx->mlx);
    }
}

void move_down(t_map *mlx)
{
    if(mlx->map[mlx->player_y + 1][mlx->player_x] != '1' && mlx->map[mlx->player_y + 1][mlx->player_x] != 'E')
    {
        if(mlx->map[mlx->player_y + 1][mlx->player_x] == 'C')
        {
            mlx->map[mlx->player_y + 1][mlx->player_x] = '0';
            mlx->coins--;
        }
        mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x *32, mlx->player_y * 32);
        mlx->player_y++;
        mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32, mlx->player_y * 32);
    }
    else if(mlx->coins == 0 && mlx->map[mlx->player_y + 1][mlx->player_x] == 'E')
    {   
        printf("Yo hoo You Win !");
        mlx_close_window(mlx->mlx);
    }
    printf("%d\n", mlx->player_y);
}
void move_right(t_map *mlx)
{
    printf("%d\n", mlx->player_x);
    if(mlx->map[mlx->player_y][mlx->player_x + 1] != '1' && mlx->map[mlx->player_y][mlx->player_x + 1] != 'E')
    {
        if(mlx->map[mlx->player_y][mlx->player_x + 1] == 'C')
        {
            mlx->map[mlx->player_y][mlx->player_x + 1] = '0';
            mlx->coins--;
        }
        mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x *32, mlx->player_y * 32);
        mlx->player_x++;
        mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32, mlx->player_y * 32);
    }
    else if(mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x + 1] == 'E')
    {
        printf("Yo hoo You Win !");   
        mlx_close_window(mlx->mlx);
    }
}

void move_left(t_map *mlx)
{
    printf("%d\n", mlx->player_x);
    if(mlx->map[mlx->player_y][mlx->player_x - 1] != '1' && mlx->map[mlx->player][mlx->player_x - 1] != 'E')
    {
        if(mlx->map[mlx->player_y][mlx->player_x - 1] == 'C')
        {
            mlx->map[mlx->player_y][mlx->player_x - 1] = '0';
            mlx->coins--;
        }
        mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x *32, mlx->player_y * 32);
        mlx->player_x--;
        mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32, mlx->player_y * 32);
    }
    // if(mlx->map[mlx->player_y][mlx->player_x] == 'E' && mlx->coins != 0)
    // {
    //     mlx->map[mlx->player_y][mlx->player_x - 1] = 'E';
    //     mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x *32, mlx->player_y * 32);
    //     mlx->player--;
    //     mlx_image_to_window(mlx->mlx, mlx->img[4], mlx->player_x * 32, mlx->player_y * 32); 
    // }
    // else if(mlx->map[mlx->player_y][mlx->player_x - 1] != '1' && mlx->map[mlx->player_y][mlx->player_x - 1] == 'E')
    // {
    //     mlx->map[mlx->player_y][mlx->player_x] = 'E';
    //     mlx_image_to_window(mlx->mlx, mlx->img[4], mlx->player_x *32, mlx->player_y * 32);
    // }
    else if(mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x - 1] == 'E')
    {
        printf("Yo hoo You Win !");
        mlx_close_window(mlx->mlx);
    }
}
