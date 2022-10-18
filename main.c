#include "cub3d.h"

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 2)
    {
        data = malloc(sizeof(t_data));
        if (all_check_and_read_map(data, av[1]))
            ft_clear(data);
        else
            exit(0);
    }
    else
        ft_error_mes();
    //ft_routine();
    return (0);
}