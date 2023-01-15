#include "cub3d.h"

int	close_frame(t_map *main)
{
	if (main->mlx_win)
		mlx_destroy_window(main->mlx, main->mlx_win);
	exit(0);
	return (0);
}

int	walk(int keycode, t_map *main)
{
	if (keycode == 53 || keycode == 12)
		close_frame(main);
	mlx_clear_window(main->mlx, main->mlx_win);
	return (keycode);
}

void    ft_routine(t_data *data, t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3_D");
    data->screen->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);//burda!
    data->screen->heigth = WIN_HEIGHT;
    data->screen->width = WIN_WIDTH;
    data->screen->addr = mlx_get_data_addr(data->screen->img, &data->screen->bbp, &data->screen->line_len, &data->screen->endian);
	mlx_hook(map->mlx_win, 2, (1L << 0), walk, map);
	mlx_hook(map->mlx_win, 17, 0, close_frame, map);
	mlx_loop(map->mlx);
}

int main(int ac, char **av)
{
    t_data      *data;
    t_map       *map;
    //t_screen    *screen;

//	data = malloc(sizeof(t_data));
//	screen = malloc(sizeof(t_screen));
	if (ac == 2)
    {
		data = malloc(sizeof(t_data));
		ft_all_check_and_read_map(data, av[1]);
		map = malloc(sizeof(t_map));
		if (!map)
			return(1);
        printf("Okey\n");
        ft_routine(data, map);
    }
    else
    {
		printf("Wrong Arg!\n");
		return (1);
    }
    //system("leaks Cub3D");
    return (0);
}