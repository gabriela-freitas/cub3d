/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:37 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/20 18:58:42 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_algorithm(t_data *data)
{
	while(data->p.rcast.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (data->p.rcast.dist_x < data->p.rcast.dist_y)
		{
			data->p.rcast.dist_x += data->p.rcast.d_x;
			data->p.rcast.map_x += data->p.rcast.step_x;
			data->p.rcast.side_hit = 0;
		}
		else
		{
			data->p.rcast.dist_y += data->p.rcast.d_y;
			data->p.rcast.map_y += data->p.rcast.step_y;
			data->p.rcast.side_hit = 1;
		}
		//Check if ray has hit a wall
		if (data->map.map[data->p.rcast.map_y][data->p.rcast.map_x] == '1')
			data->p.rcast.hit = 1;
	}
}

// cameraX is the x on the camera plane that the current x-coordinate
// of the screen represents. the right side of the screen will get
// coordinate 1, the center of the screen gets coordinate 0,
// and the left side of the screen gets coordinate -1

// d_x = distance from one x-wall to other, in this direction
// d_y = distance from one y-wall to other, in this direction

void	calculate_rays(t_data *data)
{
	int	nbr_rays;
	int	x;

	x = 0;
	nbr_rays = WIN_W - 1;
	while (x <= nbr_rays)
	{
		start_vars(data, x, nbr_rays);
		calc_vars(data);
		calc_steps(data);
		dda_algorithm(data);
		calc_draw_vars(data);
		draw_ray(data, nbr_rays, x);
		x++;
	}
	data->timers.time++;
}

void	mathematics(t_data *data)
{
	data->p.rcast.wall_height = WIN_H;
	if (data->timers.time == 0)
	{
		data->p.p_x = data->p.player_j;
		data->p.p_y = data->p.player_i;
	}
	else
	{
		data->p.player_j = (int)data->p.p_x;
		data->p.player_i = (int)data->p.p_y;
	}
	printf("p_x : %f | p_y : %f\n", data->p.p_x, data->p.p_y);
	calculate_rays(data);
}
