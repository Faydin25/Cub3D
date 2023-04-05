/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:31:59 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:32:00 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	top_wall(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_data.map[0][++i])
		if (data->map_data.map[0][i] == '0')
			return (-1);
	return (0);
}

int	bottom_wall(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_data.map[array_len(data->map_data.map) - 1][++i])
		if (data->map_data.map[array_len(data->map_data.map) - 1][i] == '0')
			return (-1);
	return (0);
}

int	left_wall(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_data.map[++i])
		if (data->map_data.map[i][0] == '0')
			return (-1);
	return (0);
}

int	ft_multi_map(t_data *data, char **lines)
{
	int		flag;
	int		i;
	char	*tmp;

	i = -1;
	flag = 0;
	while (lines[++i])
	{
		tmp = ft_strdup(ft_is_space(lines[i]));
		flag = control(tmp, flag, data, i);
		if (flag == 3)
			return (-1);
		free(tmp);
	}
	if (flag == 1)
		data->map_data.map_end = i -1;
	return (0);
}
