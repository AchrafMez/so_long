/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:12:39 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/26 13:09:13 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (-1);
	while (s[ret])
		ret++;
	return (ret);
}

char	*ft_read(int fd, char *sbuff, char *buffer)
{

	int	bytes_read;
	bytes_read = BUFFER_SIZE;
	if ((!sbuff && !buffer) || fd < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(sbuff);
			free(buffer);
			buffer = NULL;
			sbuff = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		sbuff = ft_strjoin(sbuff, buffer);
		if (contains_nl(sbuff) == 1)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (sbuff);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*sbuff = NULL;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(sbuff);
		free (buffer);
		buffer = NULL;
		sbuff = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	sbuff = ft_read(fd, sbuff, buffer);
	if (!sbuff)
		return (NULL);
	line = copy_until_nl(sbuff);
	sbuff = copy_after_nl(sbuff);
	return (line);
}
// int main()
// {
// 	// char *filename = "map.ber";
	// int fd = open("map.ber", O_RDONLY);
	// char *line = get_next_line(fd);
// 	char *line2 = get_next_line(fd);
// 	char *line3 = get_next_line(fd);
// 	char *line4 = get_next_line(fd);
// 	char *line5 = get_next_line(fd);
	// printf("%s", line);
// 	printf("%s", line2);
// 	printf("%s", line3);
// 	printf("%s", line4);
// 	printf("%s", line5);
// }