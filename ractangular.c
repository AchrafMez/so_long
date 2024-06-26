#include "so_long.h"

// typedef struct s_map{
//     int player;
//     int coins;
//     int walls;

// } t_map;

void ones_line(char *line)
{
    int i = 0;
    while(line[i] != '\0')
    {
        if(line[i] != '1')
            ft_error();
        i++;
    }
}

// typedef struct s_info{
//     int x;
//     int p;
//     int e;
//     int c;
// } t_info;

void check(char *line)
{
    int x = 0;
    static int p = 0;
    static int c = 0;
    static int e = 0;
    printf("line -> %s", line);
    while(line[x])
    {
        if(line[x] == 'E')
            e++;
        if(line[x] == 'C')
            c++;
        if(line[x] == 'P')
            p++;
        if(line[x] == '1' || line[x] == '0')
            x++;
        else if(line[x] != 'C' || line[x] != 'E' || line[x] != 'P')
            ft_error();
        x++;
    }
    if(c == 0 || p > 1 || e > 1 || e == 0 || p == 0)
    {
        printf("player -> %d\n", p);
        printf("coins -> %d\n", e);
        printf("player -> %d\n", c);
        printf("coins player and exit\n");
        return ;
    }
    return ;
}
void map_len(char **map)
{
    int y = 0;
    int len = ft_strlen(map[y]);
    int len1 = 0;
    while(map[y])
    {
        len1 = ft_strlen(map[y]);
        if(len != ft_strlen(map[y]))
        {
            printf("something wrong with lines !\n");
            return ;
        }
        else if(map[y][0] != '1')
            ft_error();
        else if(map[y][len1-1] != '1')
            ft_error();
        check(map[y]);
        y++;
    }
    ones_line(map[y - 1]);
    printf("lines are equal !\n");
    return ;
}

void map_rectangular(char **map)
{
    // t_map check;
    int y = 0;
    int x = 0;
    int len = 0;
    // int len1;
    ones_line(map[0]);
    map_len(map);
    while(map[y][x])
    {
        len = ft_strlen(map[y]);
        x++;
    }
    return ;
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
