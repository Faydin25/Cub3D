/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:34:23 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:34:24 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_all_num(char **code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (code[i])
	{
		while (code[i][j])
		{
			if (ft_isdigit(code[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	color_nbr_check(char **code)
{
	if (array_len(code) != 3)
		return (-1);
	if (check_all_num(code) == -1)
		return (-1);
	if (ft_atoi(code[0]) < 0 || ft_atoi(code[0]) > 255)
		return (-1);
	if (ft_atoi(code[1]) < 0 || ft_atoi(code[1]) > 255)
		return (-1);
	if (ft_atoi(code[2]) < 0 || ft_atoi(code[2]) > 255)
		return (-1);
	return (0);
}

int	check_f(char *s, t_data *data)
{
	char	*tmp;
	char	**code;

	s = s + 1;
	s = ft_is_space(s);
	tmp = ft_substr(s, 0, ft_strlen(s) - 1);
	tmp = last_trim(tmp);
	code = ft_split(tmp, ',');
	if (color_nbr_check(code) == -1)
	{
		free(tmp);
		array_cleaner((void **)code);
		return (-1);
	}
	data->map_data.colors[flooor][0] = ft_atoi(code[0]);
	data->map_data.colors[flooor][1] = ft_atoi(code[1]);
	data->map_data.colors[flooor][2] = ft_atoi(code[2]);
	free(tmp);
	array_cleaner((void **)code);
	return (0);
}

int	check_c(char *s, t_data *data)
{
	char	*tmp;
	char	**code;

	s = s + 1;
	s = ft_is_space(s);
	tmp = ft_substr(s, 0, ft_strlen(s) - 1);
	tmp = last_trim(tmp);
	code = ft_split(tmp, ',');
	if (color_nbr_check(code) == -1)
	{
		free(tmp);
		array_cleaner((void **)code);
		return (-1);
	}
	data->map_data.colors[ceiling][0] = ft_atoi(code[0]);
	data->map_data.colors[ceiling][1] = ft_atoi(code[1]);
	data->map_data.colors[ceiling][2] = ft_atoi(code[2]);
	free(tmp);
	array_cleaner((void **)code);
	return (0);
}

int	ft_check_rgb(char *s, char **find, int size, t_data *data)
{
	int	i;

	i = 0;
	s = ft_is_space(s);
	while (i < size)
	{
		if (!ft_strncmp(s, find[i], 1))
		{
			if (!ft_strncmp(s, "F", 1))
				if (check_f(s, data) == -1)
					return (-1);
			if (!ft_strncmp(s, "C", 1))
				if (check_c(s, data) == -1)
					return (-1);
		}
		i++;
	}
	return (0);
}
