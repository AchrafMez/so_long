#include "so_long.h"

void ft_error()
{
    write(2, "Error\n", 6);
    exit(1);
}
char *ext(char *str)
{
    // int i = 0;
    while(*str)
    {
        if(*str == '.')
            return((char *)str+1);
        str++;
    }
    return NULL;
}

int camp(char *str)
{
    char *ext = "ber";
    int i = 0;
    while(str[i])
    {
        if(str[i] != ext[i])
            return -1;
        i++;
    }
    return 0;
}
// void treat()
// {

// }

int map_lines(int fd)
{
    int i = 0;
    while(get_next_line(fd) != NULL)
        i++;
    return i;
}
#include <string.h>

void ft_strcpy(char *line, char *map)
{
    int i = 0;
    if(!line)
        return ;
    // int count = 0;
    // printf("line ->%s\n", line);
    // printf("count in strcpy function -> %d\n", count);
    while(line[i])
    {
        map[i] = line[i];
        i++;
    }
    map[i] = '\0';
    free(line);
}

void ft_free(char **map, int i)
{
    while(i--)
        free(map[i]);
    free(map);
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

int main(int ac, char **av)
{
    if(ac != 2)
        printf("Error in arguments\n");
    else
    {
        char *str = av[1];
        ext(str);
        printf("%s");
    }
}
