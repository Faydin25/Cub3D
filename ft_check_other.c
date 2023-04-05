/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:33:46 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:40:20 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_color(char **lines)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
			if (lines[i][j] == 'C' || lines[i][j] == 'F')
				count++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	ft_other_check(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
		{
			if (data->map_data.map[i][j] == 'N' ||
					data->map_data.map[i][j] == 'S' ||
					data->map_data.map[i][j] == 'E' ||
					data->map_data.map[i][j] == 'W')
				count++;
		}
	}
	if (count != 1)
		return (1);
	return (0);
}
