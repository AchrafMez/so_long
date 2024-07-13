/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:32:08 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/13 23:56:56 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press(struct mlx_key_data key_data, void *param)
{
	t_map	*mlx;

	mlx = (t_map *)param;
	if (((key_data.key == MLX_KEY_UP) || key_data.key == MLX_KEY_W)
		&& key_data.action)
		move_up(mlx);
	else if ((key_data.key == MLX_KEY_DOWN || key_data.key == MLX_KEY_S)
		&& key_data.action)
		move_down(mlx);
	else if ((key_data.key == MLX_KEY_RIGHT || key_data.key == MLX_KEY_D)
		&& key_data.action)
		move_right(mlx);
	else if ((key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_A)
		&& key_data.action)
		move_left(mlx);
	else if (key_data.key == MLX_KEY_ESCAPE)
	{
		write(1, "Oops! You didn't finish the game.\n", 34);
		if (mlx->mlx != NULL)
		{
			mlx_close_window(mlx->mlx);
			mlx->mlx = NULL;
		}
	}
}
