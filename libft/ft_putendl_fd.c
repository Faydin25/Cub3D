/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:29:18 by faydin            #+#    #+#             */
/*   Updated: 2022/01/29 01:40:14 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
/*
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
	char *a = " ramo";
	char *cb = "aeksogjaodsjop";
	int fd = open("deneme.txt",O_CREAT | O_RDWR, 0777);
	ft_putendl_fd(a,fd); 
	ft_putendl_fd(cb, fd);
	FILE *b = fopen("deneme.txt","r");
	char c;
	while(!feof(b))
	{
		c = fgetc(b);
		printf("%c",c);
	}
	fclose(b);
	return 0;
}*/
