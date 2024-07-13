/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:48:05 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 23:48:11 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_check(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				flood_fill(map, y, x);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '*' || map[y][x] == '1')
		return ;
	map[y][x] = '*';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

int	check_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
