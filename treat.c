/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:29:05 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/14 00:00:23 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	camp(char *filename)
{
	char	*ext;
	int		i;

	ext = ".ber";
	i = ft_strlen(filename) - 4;
	while (filename[i])
	{
		if (filename[i] != *ext)
			return (-1);
		ext++;
		i++;
	}
	return (0);
}

void	treat(char *filename, t_map *mlx)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Invalid map !\n", 14);
		exit(1);
	}
	else
	{
		ft_store(filename, mlx);
		player_check(mlx->map);
		if (check_path(mlx->map) == 1)
		{
			ft_free(mlx->map, mlx->y);
			write(2, "Error: the map provided does not have a valid path\n",
				52);
			exit(1);
		}
		ft_free(mlx->map, mlx->y);
		ft_store(filename, mlx);
	}
	close(fd);
}
