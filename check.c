#include "cub3d.h"

int ft_check_cub(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    i--;
    if (s[i] != 'b' && s[i - 1] != 'u' && s[i - 2] != 'c' && s[i - 3] != '.')
        return (1);
    return (0);
}