#include <string.h>
#include "so_long.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	int		len;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	new = malloc(len + 1);
// 	if (!new)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		new[i + j] = s2[j];
// 		j++;
// 	}
// 	new[i + j] = '\0';
// 	return (new);
// }
void ft_error()
{
    write(2, "Error\n", 6);
    exit(1);
}


int map_lines(int fd, char *filename)
{
    int i = 0;
    char *line = get_next_line(fd);
    fd = open(filename, fd);
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return i;
}


void ft_free(char **map, int i)
{
    while(i--)
        free(map[i]);
    free(map);
}

int camp(char *filename)
{
    char *ext = ".ber";
    int i = ft_strlen(filename) - 4;
    while(filename[i])
    {
        if(filename[i] != *ext)
            return -1;
        ext++;
        i++;
    }
    return 0;
}
// void ft_copying(char *map, char *line)
// {
//     int i = 0;
//     if(!line)
//         return ;
//     while(line[i] != '\0')
//     {
//         map[i] = line[i];
//         i++;
//     }
//     map[i] = '\0';
//     free(line);
// }

void  ft_store(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if(fd <= 0 || !filename)
        ft_error();

    int maplines = map_lines(fd, filename);
    close(fd);
    fd = open(filename, O_RDONLY);
    char **map = (char **)malloc(sizeof(char *) * (maplines + 1));
    if(!map)
        return ;
    char *line = get_next_line(fd);
    int line_len = 0;
    int i = 0;
    while(line)
    {
        line_len = ft_strlen(line);
        // map[i] = malloc(line_len + 1);
        // if(!map[i])
        // {
        //     free(line);
        //     ft_free(map, i);
        // }
        map[i]= strdup(line);
        free(line);
       // ft_copying(map[i], line);
       line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    int p = 0;
    while(map[p] != NULL)
    {
        printf("%s", map[p]);
        p++;
    }
    ft_free(map, i);
    close(fd);
}
// int map_rectangular(int fd, char *filename)
// {
//     // fd = open(filename, O_RDONLY);
//     if(fd <= 0 || !filename)
//         ft_error();
//     char *line;
//     static int len = 0;
//     int len1 = 0;
//     // int len1 = 0;
//     int nline = 0;
//     while((line = get_next_line(fd)) != NULL)
//     {
//         len += ft_strlen(line);
//         len1 = ft_strlen(line);
//         // if(len != 0 && len1 != 0 && len !=)
//         nline += 1;
//     }
//         printf("line len --> %d\n", len);
//         // printf("numbers of line --> %d\n", nline);
//     if(line[len1] == '\0')
//         len += 1;
//     if((len % nline) != 0)
//     {
//         printf("lines error");
//         return 1;
//     }
//         else
//             printf("lines correct");
//     return 0;
// }

int main(int ac, char **av)
{
    char *filename = av[1];
    int fd = open(filename, O_RDONLY);
    if(ac != 2)
        ft_error();
    else
    {
        if(camp(filename) == -1)
        {
            printf("filename error\n");
            return 1;
        }
        else
            ft_store(filename);
            // map_rectangular(fd, filename);
    }
    system("leaks so_long");
    close(fd);
}


// int main()
// {
//     char *filename = "map.ber";
//     int fd = open(filename, O_RDONLY);

//     if(camp(ext(filename)) == -1)
//     {
//         printf("Uncorrect filename");
//         return 1;
//     }
//     if(fd <= 0)
//         ft_error();
//     int count = map_lines(fd);
//     close(fd);
//     int i = 0;
//     // printf("count var - > %d\n", count);
//     char *line;
//     char **map = (char **)malloc(count + 1 * sizeof(char *));
//     if(!map)
//         return (0);
//     // printf("before the while loop\n");
//     fd = open(filename, O_RDONLY);
//     while(i < count)
//     {
//         line = get_next_line(fd);
//         // printf("line == %s", line);
//         int len = strlen(line);
//         // printf("the length %d", len);
//         // ft_strcpy(line, map);
//         map[i] = (char *)malloc(len + 1);
//         if(!map[i])
//         {
//             return 0;
//         }
//         ft_strcpy(line, map[i]);
//         // free(line);
//         // printf("in the while ");
//         i++;
//     }
//     map[count] = NULL;
//     int z = 0;
//     while(map[z])
//         printf("%s", map[z++]);
//     // printf("%s", map[5]);
//     // printf("%s", map[6]);
//     // printf("after the while loop\n");
//     // int i = map_lines(fd);
//     close(fd);
//     system("leaks so_long");
    
// }
