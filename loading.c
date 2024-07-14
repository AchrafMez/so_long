/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:27:18 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/14 02:08:37 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_png(t_map *mlx)
{
	mlx->texture[0] = mlx_load_png("./solong_assists/floor.png");
	if (!mlx->texture[0])
		exit(1);
	mlx->texture[1] = mlx_load_png("./solong_assists/wall.png");
	if (!mlx->texture[1])
		exit(1);
	mlx->texture[2] = mlx_load_png("./solong_assists/player.png");
	if (!mlx->texture[2])
		exit(1);
	mlx->texture[3] = mlx_load_png("./solong_assists/coin.png");
	if (!mlx->texture[3])
		exit(1);
	mlx->texture[4] = mlx_load_png("./solong_assists/exit.png");
	if (!mlx->texture[4])
		exit(1);
}

void	png_to_image(t_map *mlx)
{
	mlx->img[0] = mlx_texture_to_image(mlx->mlx, mlx->texture[0]);
	mlx->img[1] = mlx_texture_to_image(mlx->mlx, mlx->texture[1]);
	mlx->img[2] = mlx_texture_to_image(mlx->mlx, mlx->texture[2]);
	mlx->img[3] = mlx_texture_to_image(mlx->mlx, mlx->texture[3]);
	mlx->img[4] = mlx_texture_to_image(mlx->mlx, mlx->texture[4]);
}

void	ft_put_floor(t_map *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map[y])
	{
		while (mlx->map[y][x])
		{
			mlx_image_to_window(mlx->mlx, mlx->img[0], x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_put_exit(t_map *mlx)
{
	mlx_image_to_window(mlx->mlx, mlx->img[4], mlx->exit_x * 32, mlx->exit_y
		* 32);
}

void	put_pictures(t_map *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (mlx->map[y])
	{
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E')
				mlx_image_to_window(mlx->mlx, mlx->img[4], x * 32, y * 32);
			else if (mlx->map[y][x] == '0')
				mlx_image_to_window(mlx->mlx, mlx->img[0], x * 32, y * 32);
			else if (mlx->map[y][x] == '1')
				mlx_image_to_window(mlx->mlx, mlx->img[1], x * 32, y * 32);
			else if (mlx->map[y][x] == 'P')
				mlx_image_to_window(mlx->mlx, mlx->img[2], x * 32, y * 32);
			else if (mlx->map[y][x] == 'C')
				mlx_image_to_window(mlx->mlx, mlx->img[3], x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}
