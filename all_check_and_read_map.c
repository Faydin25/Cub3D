#include "cub3d.h"

void    ft_read_map(t_data *data, char *cubfile)
{
    int     i;
    int     fd;
    char    *line;
    char    *result;

    i = 0;
    fd = open(cubfile, O_RDONLY);
    result = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        result = ft_strjoin(result, line);
        free(line);
    }
    data->map = ft_split(result, '\n');
    free(result);
}

void    ft_adjust(char **map)
{
    int i;
    int j;

    j = 0;
    while (map[j] && map[j][0] != '1')
        j++;
    while (map[j])
    {
        i = -1;
        while (map[j][++i])
        {
            if (map[j][i] == ' ')
                map[j][i] = '1';
        }
        j++;
    }
}

void    ft_all_check_and_read_map(t_data *data, char *map)
{
    if (ft_check_cub(map))
    {
        free(data);
        printf("Extension Wrong!\n");
        exit(0);
    }
    ft_read_map(data, map);
    ft_adjust(data->map);
    ft_check_wall(data);
    ft_check_map(data);
    ft_check_for_long(data);
}