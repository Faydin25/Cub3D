/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:33:12 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:33:13 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_func(int keycode, t_data *data)
{
	if (keycode == Key_W || keycode == Key_A || keycode == Key_S
		|| keycode == Key_D)
		ft_move(keycode, data);
	if (keycode == key_rt)
		data->player.direction += 3;
	if (keycode == key_lt)
		data->player.direction -= 3;
	if (data->player.direction >= 360)
		data->player.direction = ft_abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		ft_exit(data);
	render_window(data);
	return (0);
}
