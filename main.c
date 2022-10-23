#include "cub3d.h"

void    ft_routine(t_data *data)
{
    //mlx_init();
    //mlx_new_window();
    //ft_put_image(data);
    ;
}

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 2)
    {
        data = malloc(sizeof(t_data));
        ft_all_check_and_read_map(data, av[1]);
        printf("Okey");
        ft_routine(data);
    }
    else
        printf("Wrong Arg!\n");
    return (0);
}