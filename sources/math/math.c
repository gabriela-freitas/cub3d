/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:55:37 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/19 18:00:52 by gafreita         ###   ########.fr       */
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
	printf("dist x : %f | dist y : %f\n", data->p.rcast.dist_x, data->p.rcast.dist_y);
}

/* void	calc_draw(t_data *data)
{
	int	draw;
	if (!data->p.rcast.side_hit)
	{
		if (data->p.rcast.p_dir_y < 0)
			draw = -1;
		else
			draw = 1;
	}
	else
	{
		if (data->p.rcast.p_dir_x < 0)
			draw = -2;
		else
			draw = 2;
	}
	if (draw == 2)
		//draw N
	else if (draw == -2)
		//draw S
	else if (draw == 1)
		//draw E
	else if (draw == -1)
		//draw W

} */

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
	data->p.rcast.fov_x = 0;
	data->p.rcast.fov_y = 0.66;
	//printf("p_x: %f | p_y : %f\n", data->p.p_x, data->p.p_y);
	//printf("map_x: %d | map_y : %d\n", data->p.rcast.map_x, data->p.rcast.map_y);
	//printf("\n\n");
	while (x <= nbr_rays)
	{
		start_vars(data, x, nbr_rays);
		calc_vars(data);
		calc_steps(data);
		dda_algorithm(data);
		calc_draw_vars(data);
		draw_ray(data, nbr_rays, x);
		//calc_draw(data);
		//draw
		x++;
	}
}

void	mathematics(t_data *data)
{
	data->timers.time = 0;
	data->timers.old_time = 0;
	data->p.rcast.wall_height = WIN_H;
	// while (1)
	// {
	calculate_rays(data);
	// 	break ;
	// }
}
