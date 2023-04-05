/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:34:52 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:34:53 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

double	ft_sqrt(double var)
{
	double	i;
	double	j;

	i = 0;
	j = var / 2;
	while (j != i)
	{
		i = j;
		j = (var / i + i) / 2;
	}
	return (j);
}
