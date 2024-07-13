/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ractangular.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:46:12 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 21:43:46 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ones_line(t_map *mlx, int y)
{
	int x;

	x = 0;
	while (mlx->map[y][x] != '\0')
	{
		if (mlx->map[y][x] != '1')
			ft_error(mlx);
		x++;
	}
}

int	map_check(t_map *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx->player = 0;
	mlx->exit = 0;
	mlx->player_x = 0;
	mlx->player_y = 0;
	mlx->coins = 0;
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
int	map_len(t_map *mlx)
{
	int	y;
	int	len;
	int	len1;

	y = 0;
	len = ft_strlen(mlx->map[y]);
	len1 = 0;
	while (mlx->map[y])
	{
		len1 = ft_strlen(mlx->map[y]);
		if (len != ft_strlen(mlx->map[y]))
			return (1);
		else if (mlx->map[y][0] != '1')
			return (1);
		else if (mlx->map[y][len1 - 1] != '1')
			return (1);
		else if (check(mlx->map[y]) == 1)
			return (1);
		y++;
	}
	ones_line(mlx, y - 1);
	if (map_check(mlx) == 1)
		return (1);
	else
		return (0);
}

int	map_rectangular(t_map *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	ones_line(mlx, 0);
	if (map_len(mlx) == 1)
		ft_error(mlx);
	while (mlx->map[mlx->y][mlx->x])
		mlx->x++;
	while (mlx->map[mlx->y])
		mlx->y++;
	if (mlx->y > 43 || mlx->x > 80)
	{
		write(2, "map size bigger then mac size!\n", 31);
		exit(1);
	}
	return (0);
}
