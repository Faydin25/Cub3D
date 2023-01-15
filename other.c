//
// Created by Onur Dursun on 1/15/23.
//

#include "cub3d.h"

int ft_variable(char *s)
{
	(void)s;
	// burada "," gelen sayılar ayrılacak
	// ayrılacak sayılar integere dönüştürülecek
	// dönüştürülen sayılar rgb kontrolleri yapılacak
	// duruma göre return 1 veya 0 dönecek
	return  1;
}

//mapteki harf kontrolü burada sağlanmaktadır.
void	ft_check_value(char *s, int *t)
{
	char **tab;

	tab = ft_split(s, ' ');
	if (!ft_strncmp(tab[0], "NO\0", 3))
		(*t)++;
	else if (!ft_strncmp(tab[0], "SO\0", 3))
		(*t)++;
	else if (!ft_strncmp(tab[0], "WE\0", 3))
		(*t)++;
	else if (!ft_strncmp(tab[0], "EA\0", 3))
		(*t)++;
	else if (!ft_strncmp(tab[0], "F\0", 2))
	{
		if (ft_variable(tab[1]))
			exit(1);
	}
	else if (!ft_strncmp(tab[0], "C\0", 2))
	{
		if (ft_variable(tab[1]))
			exit(1);
	}
	int i = -1;
	while (tab[++i])
		if (tab[i])
			free(tab[i]);
}