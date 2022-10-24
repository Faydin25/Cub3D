#include "cub3d.h"

void    ft_routine(t_data *data, t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3_D");
    data->screen->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
    data->screen->heigth = WIN_HEIGHT;
    data->screen->width = WIN_WIDTH;
    
    //mlx_loop(map->mlx);
}

int main(int ac, char **av)
{
    t_data  *data;
    t_map   *map;

    if (ac == 2)
    {
        data = malloc(sizeof(t_data));
        ft_all_check_and_read_map(data, av[1]);
        printf("Okey");
        ft_routine(data, map);
    }
    else
        printf("Wrong Arg!\n");
    return (0);
}