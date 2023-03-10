/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:17:13 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/03/07 17:18:16 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	start_vars(t_data *data, int x, int nbr_rays)
{
	data->p.rcast.hit = 0;
	data->p.rcast.map_x = data->p.player_j;
	data->p.rcast.map_y = data->p.player_i;
	data->p.rcast.cam_x = 2 * (double)x / (double)nbr_rays - 1;
}

// calculates the initial direction of the player

// calculates the direction of the ray -> ray_x & ray_y,
//            the distance between planes in the x and y directions -> d_x & d_y

void	calc_vars(t_data *data)
{
	data->p.rcast.ray_x = data->p.rcast.p_dir_x + data->p.rcast.fov_x * \
	data->p.rcast.cam_x;
	data->p.rcast.ray_y = data->p.rcast.p_dir_y + data->p.rcast.fov_y * \
	data->p.rcast.cam_x;
	if (data->p.rcast.ray_x != 0)
		data->p.rcast.d_x = fabs(1.0 / data->p.rcast.ray_x);
	else
		data->p.rcast.d_x = -1;
	if (data->p.rcast.ray_y != 0.000)
		data->p.rcast.d_y = fabs(1.0 / data->p.rcast.ray_y);
	else
		data->p.rcast.d_y = -1;
}

// calculates the distance to the camera plane,
//            the pixel that starts and the one that ends drawing vertically.

void	calc_draw_vars(t_data *data)
{
	if (data->p.rcast.side_hit == 0)
		data->p.rcast.cam_plane_dist = (data->p.rcast.dist_x - \
		data->p.rcast.d_x);
	else
		data->p.rcast.cam_plane_dist = (data->p.rcast.dist_y - \
		data->p.rcast.d_y);
	data->p.rcast.line_height = (int)(WIN_H / \
	data->p.rcast.cam_plane_dist);
	data->p.rcast.draw_start = -data->p.rcast.line_height / 2 + \
	WIN_H / 2;
	data->p.rcast.draw_end = data->p.rcast.line_height / 2 + \
	WIN_H / 2;
}

// calculates the direction and size of each step both for x and y

void	calc_stps(t_data *data)
{
	if (data->p.rcast.ray_y < 0 && data->p.rcast.d_y > 0)
	{
		data->p.rcast.step_y = -1;
		data->p.rcast.dist_y = (data->p.p_y - data->p.player_i) \
		* data->p.rcast.d_y;
	}
	else if (data->p.rcast.d_y > 0)
	{
		data->p.rcast.step_y = 1;
		data->p.rcast.dist_y = (data->p.player_i + 1.0 - data->p.p_y) \
		* data->p.rcast.d_y;
	}
	else
	{
		data->p.rcast.step_y = 0;
		data->p.rcast.dist_y = INF;
	}
}

void	calc_steps(t_data *data)
{
	if (data->p.rcast.ray_x < 0 && data->p.rcast.d_x > 0)
	{
		data->p.rcast.step_x = -1;
		data->p.rcast.dist_x = (data->p.p_x - data->p.player_j) \
		* data->p.rcast.d_x;
	}
	else if (data->p.rcast.d_x > 0)
	{
		data->p.rcast.step_x = 1;
		data->p.rcast.dist_x = (data->p.player_j + 1.0 - data->p.p_x) \
		* data->p.rcast.d_x;
	}
	else
	{
		data->p.rcast.step_x = 0;
		data->p.rcast.dist_x = INF;
	}
	calc_stps(data);
}
