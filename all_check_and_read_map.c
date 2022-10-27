#include "cub3d.h"

void    ft_check_have_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[j] && data->map[j][0] != '1')
        j++;
    if (data->map[j] == 0)
    {
        printf("Map Error!\n");
        ft_clear(data);
        exit(0);
    }
}

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

int ft_len(char **map)
{
    int j;
    int i;
    int max;

    j = 0;
    while (map[j] && map[j][0] != '1')
        j++;
    max = 0;
    while (map[j])
    {
        i = 0;
        while (map[j][i])
            i++;
        if (i > max)
            max = i;
        j++;
    }
    return (max);
}

void    ft_addjust2(t_data *data ,char **map)
{
    int len;
    int j;
    int i;

    j =  data->first_line;
    while (map[j])
    {
        if (map[j][0] == '\n')
        {
            i = 0;
            len = ft_len(map);
            map[j] = (char *)malloc(sizeof(len + 1));
            while (i <= len)
                map[j][i++] = '1';
            map[j][i] = '\0';
        }
        j++;
    }
}

void    ft_adjust(t_data *data, char **map)
{
    int i;
    int j;

    j = data->first_line;
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
    ft_addjust2(data,map);
    i = 0;
    j = data->first_line;
    printf("--------------------------\n");
    while (map[j])
    {
        printf("%s\n", map[j]);
        j++;
    }
    printf("--------------------------\n");
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
    ft_check_have_map(data);
    ft_find(data);
    ft_adjust(data ,data->map);
    ft_check_wall(data);
    ft_check_map(data);
    ft_check_for_long(data);
    ft_check_once_to_map(data);
    ft_check_file(data);
}