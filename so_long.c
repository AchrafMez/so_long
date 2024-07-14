/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:59:54 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/14 02:04:51 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_map	mlx;
	char	*filename;

	if (ac != 2)
	{
		write(2, "Arguments Error\n", 17);
		return (1);
	}
	filename = av[1];
	if (camp(filename) == -1)
		ft_camp_error();
	treat(filename, &mlx);
	load_png(&mlx);
	mlx.width = mlx.x * 32;
	mlx.height = mlx.y * 32;
	mlx.mlx = mlx_init(mlx.width, mlx.height, "so_long", false);
	png_to_image(&mlx);
	ft_put_floor(&mlx);
	get_e(&mlx);
	put_pictures(&mlx);
	mlx_key_hook(mlx.mlx, key_press, &mlx);
	mlx_loop(mlx.mlx);
	ft_free(mlx.map, mlx.y);
	delete_texture(&mlx);
}
