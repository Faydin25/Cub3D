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

void    ft_check_map_next(t_data *data)
{
    int i;
    int j;
    int k;

    i = -1;
    j = data->first_line;
    k = 0;
    while (data->map[--j])
    {
        i = -1;
        while (data->map[j][++i])
        {
            if (data->map[j][i] == 'N' || data->map[j][i] == 'S' || \
                data->map[j][i] == 'W' || data->map[j][i] == 'E' || \
                data->map[j][i] == 'F' || data->map[j][i] == 'C')
                k++;
                break ;
        }
    }
    if (k != 6)
    {
        printf("Map Error!\n");
        ft_clear(data);
        exit(0);
    }
}

void    ft_check_map(t_data *data)
{
    int i;
    int j;

    j = data->first_line;
    while (data->map[j])
    {
        i = -1;
        while (data->map[j][++i])
        {
            if (data->map[j][i] != '1' && data->map[j][i] != '0' && \
            data->map[j][i] != 'N' && data->map[j][i] != 'S' && \
            data->map[j][i] != 'W' && data->map[j][i] != 'E' && data->map[j][i] != '\n')
            {
                printf("Wrong Map!\n");
                ft_clear(data);
                exit(0);
            }
        }
        j++;
    }
    ft_check_map_next(data);
}

void    ft_check_wall_next(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = data->first_line - 1;
    while (data->map[++j])
    {
        if (data->map[j][0] != '1')
        {
            printf("Wrong Map!\n");
            ft_clear(data);
            exit(0);
        }
    }
}

void    ft_check_wall(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = -1;
    while (data->map[i] && data->map[i][0] != '1')
        i++;
    data->first_line = i;
    while (data->map[i][++j])
    {
        if (data->map[i][j] != '1')
        {
            printf("Wrong Map!\n");
            ft_clear(data);
            exit(0);
        }
    }
    i = 0;
    while (data->map[i])
        i++;
    i--;
    j = -1;
    while (data->map[i][++j])
    {
        if (data->map[i][j] != '1')
        {
            printf("Wrong Map!");
            ft_clear(data);
            exit(0);
        }
    }
    ft_check_wall_next(data);
}