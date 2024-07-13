/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:42:34 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 23:58:12 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_map *mlx)
{
	mlx->player = 0;
	mlx->exit = 0;
	mlx->player_x = 0;
	mlx->player_y = 0;
	mlx->coins = 0;
}

void	map_check_helper(t_map *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'E')
				mlx->exit++;
			else if (mlx->map[y][x] == 'C')
				mlx->coins++;
			else if (mlx->map[y][x] == 'P')
			{
				mlx->player_y = y;
				mlx->player_x = x;
				mlx->player++;
			}
			x++;
		}
		y++;
	}
}

int	map_check(t_map *mlx)
{
	init(mlx);
	map_check_helper(mlx);
	if (mlx->coins <= 0 || mlx->player <= 0 || mlx->player > 1 || mlx->exit <= 0
		|| mlx->exit > 1)
		return (1);
	else
		return (0);
}

int	check(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != '0' && line[x] != 'C' && line[x] != 'E'
			&& line[x] != 'P')
			return (1);
		x++;
	}
	return (0);
}
