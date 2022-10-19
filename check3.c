#include "cub3d.h"

void    ft_go_color(char *line, t_data *data , int i)
{
    int j;
    int nbr;

    j = 0;
    while (line[++i])
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            nbr = ft_atoi(line + i);
            if (nbr >= 256 || nbr < 0)
            {
                printf("Error!\n");
                ft_clear(data);
                exit(0);
            }
            while (line[i] && line[i] != ',')
                i++;
        }
        else if (!(line[i] == ' ' || line[i] == '\n' || line[i] == ','))
        {
            printf("%c\n-%i", line[i], i);//ne alaka aq
            printf("Error!\n");
            ft_clear(data);
            exit(0);
        }
    }
}

void    ft_control_line(t_data *data, int j)
{
    int i;
    int total;
    int k;

    k = 0;
    while (--j >= 0)
    {
        i = 0;
        while (data->map[j][i] && data->map[j][i] != '\n')
        {
            if (data->map[j][i] == 'F' || data->map[j][i] == 'C')
            {
                ft_go_color(data->map[j], data, i);
                total++;
                break ;
            }
            else if (data->map[j][i] == 'N' || data->map[j][i] == 'S')
            {
                total++;
                break ;
            }
            else if (data->map[j][i] == 'W' || data->map[j][i] == 'E')
            {
                total++;
                break ;
            }
            else if (!(data->map[j][i] == '\n' || data->map[j][i] == ' '))
            {
                printf("Map Error!\n");
                ft_clear(data);
                exit(0);
            }
            i++;
        }
    }
    if (total != 6)
    {
        printf("Map Error!\n");
        ft_clear(data);
        exit(0);
    }
    printf("eee\n");
}

void    ft_check_once_to_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = data->first_line;
    ft_control_line(data, j);
}