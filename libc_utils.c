#include "so_long.h"

// int ft_strlen(char *str)
// {
//     int i = 0;
//     while(str[i])
//         i++;
//     return i; 
// }
// char *ft_strdup(char *str)
// {
//     int i = 0;
//     char *dup = malloc(ft_strlen(str) + 1);
//     while(str[i])
//     {
//         dup[i] = str[i];
//         i++;
//     }
//     dup[i] = '\0';
//     return dup;
// }

// //return a substring from the giver string
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (*s == 0 || start > (unsigned int)(size - 1))
		return (ft_strdup(""));
	if (len <= (size - start))
		new = malloc(len + 1);
	else
		new = malloc((size - start) + 1);
	if (!new)
		return (NULL);
	while (s[i + start] && (i < len))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

//count how much word in string
static int count(char *str, char c)
{
    int count = 0;

    while(*str)
    {
        while(*str == c)
            str++;
        if(*str)
            count++;
        while(*str && *str != c)
            str++;
    }
    return count;
}
//count the word lenght
static int word_len(char *str, char c, int i)
{
    int ret = 0;
    while(str[ret + i] && str[ret + i] != c)
        ret++;
    return ret;
}

static void ft_free(char **new, int word)
{
    while(word >= 0)
    {

        free(new[word]);
        word--;
    }
    free(new);
}

//main split function
char **ft_split(char *str, char c)
{
    int i = 0;
    int word = 0;
    char **res;

    res = (char **)malloc(sizeof(char *) * (count(str, c) + 1));
    if(!res)
        return NULL;
    while(str && str[i] != '\0' && word < count(str, c))
    {
        while(str[i] && str[i] == c)
            i++;
        res[word] = ft_substr(str, i, word_len(str, c, i));
        if(!res[word])
        {
            ft_free(res, word);
            return NULL;
        }
        i += word_len(str, c, i); 
        word++;
    }
    res[word] = NULL;
    return res;
}
