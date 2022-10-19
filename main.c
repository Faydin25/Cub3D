#include "cub3d.h"

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 2)
    {
        data = malloc(sizeof(t_data));
        ft_all_check_and_read_map(data, av[1]);
        printf("Okey");
        //ft_routine();
    }
    else
        printf("Wrong Arg!\n");
    return (0);
}