/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 05:16:42 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 23:59:16 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_e(t_map *mlx)
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
			{
				mlx->exit_y = y;
				mlx->exit_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	move_up(t_map *mlx)
{
	if (mlx->map[mlx->player_y - 1][mlx->player_x] != '1')
	{
		ft_printf("moves: %d\n", mlx->moves);
		mlx->moves += 1;
		if (mlx->map[mlx->player_y - 1][mlx->player_x] == 'C'
			&& mlx->map[mlx->player_y - 1][mlx->player_x] != 'E')
		{
			mlx->map[mlx->player_y - 1][mlx->player_x] = '0';
			mlx->coins--;
		}
		mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x * 32,
			mlx->player_y * 32);
		mlx->player_y--;
		ft_put_exit(mlx);
		mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32,
			mlx->player_y * 32);
	}
	if (mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x] == 'E')
	{
		ft_printf("YooHoo You win!");
		mlx_close_window(mlx->mlx);
	}
}

void	move_down(t_map *mlx)
{
	if (mlx->map[mlx->player_y + 1][mlx->player_x] != '1')
	{
		ft_printf("moves: %d\n", mlx->moves);
		mlx->moves += 1;
		if (mlx->map[mlx->player_y + 1][mlx->player_x] == 'C'
			&& mlx->map[mlx->player_y + 1][mlx->player_x] != 'E')
		{
			mlx->map[mlx->player_y + 1][mlx->player_x] = '0';
			mlx->coins--;
		}
		mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x * 32,
			mlx->player_y * 32);
		mlx->player_y++;
		ft_put_exit(mlx);
		mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32,
			mlx->player_y * 32);
	}
	if (mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x] == 'E')
	{
		ft_printf("YooHoo You win!");
		mlx_close_window(mlx->mlx);
	}
}

void	move_right(t_map *mlx)
{
	if (mlx->map[mlx->player_y][mlx->player_x + 1] != '1')
	{
		ft_printf("moves: %d\n", mlx->moves);
		mlx->moves += 1;
		if (mlx->map[mlx->player_y][mlx->player_x + 1] == 'C'
			&& mlx->map[mlx->player_y][mlx->player_x + 1] != 'E')
		{
			mlx->map[mlx->player_y][mlx->player_x + 1] = '0';
			mlx->coins--;
		}
		mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x * 32,
			mlx->player_y * 32);
		mlx->player_x++;
		ft_put_exit(mlx);
		mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32,
			mlx->player_y * 32);
	}
	if (mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x] == 'E')
	{
		ft_printf("YooHoo You win!");
		mlx_close_window(mlx->mlx);
	}
}

void	move_left(t_map *mlx)
{
	if (mlx->map[mlx->player_y][mlx->player_x - 1] != '1')
	{
		ft_printf("moves: %d\n", mlx->moves);
		mlx->moves += 1;
		if (mlx->map[mlx->player_y][mlx->player_x - 1] == 'C'
			&& mlx->map[mlx->player][mlx->player_x - 1] != 'E')
		{
			mlx->map[mlx->player_y][mlx->player_x - 1] = '0';
			mlx->coins--;
		}
		mlx_image_to_window(mlx->mlx, mlx->img[0], mlx->player_x * 32,
			mlx->player_y * 32);
		mlx->player_x--;
		ft_put_exit(mlx);
		mlx_image_to_window(mlx->mlx, mlx->img[2], mlx->player_x * 32,
			mlx->player_y * 32);
	}
	if (mlx->coins == 0 && mlx->map[mlx->player_y][mlx->player_x] == 'E')
	{
		ft_printf("YooHoo You win!");
		mlx_close_window(mlx->mlx);
	}
}
