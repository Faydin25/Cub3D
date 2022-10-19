#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

typedef struct s_cub3d
{
    char    **map;
    int     first_line;
}           t_data;

int     ft_check_cub(char *s);
void    ft_clear(t_data *data);
void    ft_check_map(t_data *data);
void    ft_check_wall(t_data *data);
void    ft_all_check_and_read_map(t_data *data, char *map);
void    ft_check_for_long(t_data *data);
void    ft_check_once_to_map(t_data *data);

#endif