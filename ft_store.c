/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:48:40 by amezioun          #+#    #+#             */
/*   Updated: 2024/07/14 01:34:54 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_map(void)
{
	ft_printf("The map is empty");
	exit(1);
}

int	map_lines(int fd, char *filename)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	ft_store(char *filename, t_map *mlx)
{
	int		fd;
	int		maplines;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	maplines = map_lines(fd, filename);
	mlx->map = (char **)malloc(sizeof(char *) * (maplines + 1));
	if (!mlx->map)
		return ;
	line = get_next_line(fd);
	if (!line)
		empty_map();
	i = 0;
	while (line)
	{
		mlx->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	mlx->map[i] = NULL;
	map_rectangular(mlx);
	close(fd);
}
