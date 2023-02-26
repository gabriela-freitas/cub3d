/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:37 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/26 19:05:43 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_algorithm(t_data *data)
{
	while (data->p.rcast.hit == 0)
	{
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
	double wallX; //where exactly the wall was hit
	//wallX *= 64;
	while (x <= nbr_rays)
	{
		start_vars(data, x, nbr_rays);
		calc_vars(data);
		calc_steps(data);
		dda_algorithm(data);
		calc_draw_vars(data);
		//calculate value of wallX
		if (data->p.rcast.side_hit == 0)
			wallX = data->p.p_y + data->p.rcast.cam_plane_dist * data->p.rcast.ray_y;
		else
			wallX =  data->p.p_x + data->p.rcast.cam_plane_dist * data->p.rcast.ray_x;
		wallX -= floor((wallX));
		draw_ray(data, nbr_rays, x, wallX);
		x++;
	}
	data->timers.time++;
}

void	mathematics(t_data *data)
{
	data->p.rcast.wall_height = WIN_H; //remover porque isso e const
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
	// printf("p_x : %f | p_y : %f\n", data->p.p_x, data->p.p_y);
	calculate_rays(data);
}
