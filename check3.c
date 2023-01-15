#include "cub3d.h"

void    ft_check_file(t_data *data)
{
    (void)data;
    /*
    int fd;

    fd = open("./picture/...", O_RDONLY, 777); 
    if (fd < 0)
    {
        printf("Wrong Path!\n");
        ft_clear(data);
        exit(0);
    }
    fd = open("./picture/...", O_RDONLY, 777);
    if (fd < 0)
    {
        printf("Wrong Path!\n");
        ft_clear(data);
        exit(0);
    }
    fd = open("./picture/...", O_RDONLY, 777);
    if (fd < 0)
    {
        printf("Wrong Path!\n");
        ft_clear(data);
        exit(0);
    }
    fd = open("./picture/...", O_RDONLY, 777);
    if (fd < 0)
    {
        printf("Wrong Path!\n");
        ft_clear(data);
        exit(0);
    }*/
}

int ft_check_six(char **map)
{
    int i;
    int j;
    int t;

    j = 0;
    t = 0;
    while (map[j] && map[j][0] != '1')
        j++;
    while(--j >= 0)
    {
        i = -1;
        while (map[j][++i])
        {
            if (ft_strnstr(&map[j][i], "NO", 2))
                t++;
            if (ft_strnstr(&map[j][i], "SO", 2))
                t++;
            if (ft_strnstr(&map[j][i], "WE", 2))
                t++;
            if (ft_strnstr(&map[j][i], "EA", 2))
                t++;
        }
    }
    if (t != 4)
        return (1);
    return (0);
}

void    ft_go_color(char *line, t_data *data , int i)
{
    int nbr;
    int t;

    t = 0;
    while (line[++i])
    {
        if (line[i] == ',')
            t++;
        if (line[i] >= '0' && line[i] <= '9')
        {
            nbr = ft_atoi(line + i);
            if (nbr >= 256 || nbr < 0)
            {
                printf("Error!\n");
                ft_clear(data);
                exit(0);
            }
        }
        else if (!(line[i] == ' ' || line[i] == '\n' || line[i] == ','))
        {
            printf("Error!\n");
            ft_clear(data);
            exit(0);
        }
    }
    if (t != 2)
    {
        printf("Error!\n");
        ft_clear(data);
        exit(0);
    }
}

void    ft_control_line(t_data *data, int j)
{
    int i;

    while (--j >= 0)
    {
        i = 0;
        while (data->map[j][i] && data->map[j][i] != '\n')
        {
            if (data->map[j][i] == 'F' || data->map[j][i] == 'C')
            {
                ft_go_color(data->map[j], data, i);
                break ;
            }
            else if (data->map[j][i] == 'N' || data->map[j][i] == 'S')
                break ;
            else if (data->map[j][i] == 'W' || data->map[j][i] == 'E')
                break ;
            else if (!(data->map[j][i] == '\n' || data->map[j][i] == ' '))
            {
                printf("Map Error!\n");
                ft_clear(data);
                exit(0);
            }
            i++;
        }
    }
    if (ft_check_six(data->map))
    {
        printf("Map Error!\n");
        ft_clear(data);
        exit(0);
    }
}

void    ft_check_once_to_map(t_data *data)
{
    int j;

    j = data->first_line;
    ft_control_line(data, j);
}