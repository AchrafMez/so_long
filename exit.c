/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:30:39 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 23:47:43 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_texture(t_map *mlx)
{
	int	i;

	i = 4;
	while (i >= 0)
	{
		mlx_delete_texture(mlx->texture[i]);
		i--;
	}
}

void	ft_error_free(t_map *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}

void	ft_error(t_map *mlx)
{
	write(2, "Error adsf\n", 11);
	ft_error_free(mlx);
	exit(1);
}

void	ft_free(char **map, int i)
{
	while (i--)
		free(map[i]);
	free(map);
}
