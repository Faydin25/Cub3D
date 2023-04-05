/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Batary_Comp <batary@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:33:52 by Batary_Comp       #+#    #+#             */
/*   Updated: 2023/02/13 22:33:53 by Batary_Comp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_req(t_vector2 *start, t_data *data,
			t_vector2 *sin_cos, double angle)
{
	*start = (t_vector2){.x = data->player.pos.x * 64, data->player.pos.y * 64};
	*sin_cos = (t_vector2){.x = cos((angle + data->player.direction \
	- (data->player.fov / 2)) * M_PI / 180), .y = sin((angle \
	+ data->player.direction - (data->player.fov / 2)) * M_PI / 180)};
}

void	draw_ray(t_ray_data *ray_data, t_vector2 *ray,
		t_data *data, t_vector2 sin_cos)
{
	int	wall;

	wall = 0;
	while (!wall)
	{
		(*ray_data).last_location = (*ray_data).wall_location;
		(*ray).y += sin_cos.y;
		(*ray).x += sin_cos.x;
		(*ray_data).wall_location = (t_llocation){.x = (int)(*ray).x / 64,
			.y = (int)(*ray).y / 64};
		(*ray_data).for_wall = (t_vector2){.x = (*ray).x / 64,
			.y = (*ray).y / 64};
		wall = data->map_data.int_map[(int)floor((*ray_data).wall_location.y)] \
		[(int)floor((*ray_data).wall_location.x)];
	}
}

t_ray_data	calculate_ray(t_data *data, double angle)
{
	t_ray_data	ray_data;
	t_vector2	ray;
	t_vector2	start;
	t_vector2	sin_cos;

	init_req(&start, data, &sin_cos, angle);
	ray = (t_vector2){.y = start.y, .x = start.x};
	ray_data.wall_location = (t_llocation){.x = (int)ray.x / 64,
		.y = (int)ray.y / 64};
	draw_ray(&ray_data, &ray, data, sin_cos);
	ray_data.ray_location = (t_vector2){.x = ft_fabs(ray.x - start.x),
		.y = (ray.y - start.y)};
	return (ray_data);
}

void	ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_my_get_pixel(t_data *data, int x, int y, int i)
{
	char	*dst;

	dst = data->xpm[i].img_ptr + (y * data->xpm[i].line_len + x
			* (data->xpm[i].bpp / 8));
	return (*(unsigned int *)dst);
}
