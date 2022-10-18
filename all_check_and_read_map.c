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

void    ft_all_check_and_read_map(t_data *data, char *map)
{
    if (ft_check_cub(map))
        ft_error_mes();
    ft_read_map(data, map);
    if (ft_check_arg(data->map))
    
}