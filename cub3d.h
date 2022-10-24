#ifndef CUB3D_H
# define CUB3D_H
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
# include "./lib/minilibx/mlx.h"

typedef struct s_screen
{
    int         width;
    int         heigth;
    void        *img;
}               t_screen;

typedef struct s_data
{
    char        **map;
    int         first_line;
    t_screen    *screen;
}               t_data;

typedef struct s_map
{
    void    *mlx;
    void    *mlx_win;
}           t_map;

int     ft_check_cub(char *s);
void    ft_clear(t_data *data);
void    ft_check_map(t_data *data);
void    ft_check_wall(t_data *data);
void    ft_all_check_and_read_map(t_data *data, char *map);
void    ft_check_for_long(t_data *data);
void    ft_check_once_to_map(t_data *data);
void    ft_addjust2(char **map);
void    ft_check_file(t_data *data);

#endif