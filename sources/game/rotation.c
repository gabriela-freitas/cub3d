/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:14:01 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/20 18:31:21 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double old_dir_x;
	double old_fov_x;

	old_fov_x = data->p.rcast.fov_x;
	old_dir_x = data->p.rcast.p_dir_x;
	data->p.rcast.p_dir_x = data->p.rcast.p_dir_x * cos(data->p.move.ang_var) - data->p.rcast.p_dir_y * sin(data->p.move.ang_var);
	data->p.rcast.p_dir_y = + old_dir_x * sin(data->p.move.ang_var) + data->p.rcast.p_dir_y * cos(data->p.move.ang_var);
	data->p.rcast.fov_x = data->p.rcast.fov_x * cos(data->p.move.ang_var) - data->p.rcast.fov_y * sin(data->p.move.ang_var);
	data->p.rcast.fov_y = + old_fov_x * sin(data->p.move.ang_var) + data->p.rcast.fov_y * cos(data->p.move.ang_var);
	data->p.move.flag = 1;
}

void	rotate_right(t_data *data)
{
	double old_dir_x;
	double old_fov_x;

	old_fov_x = data->p.rcast.fov_x;
	old_dir_x = data->p.rcast.p_dir_x;
	data->p.rcast.p_dir_x = data->p.rcast.p_dir_x * cos(-data->p.move.ang_var) - data->p.rcast.p_dir_y * sin(-data->p.move.ang_var);
	data->p.rcast.p_dir_y = + old_dir_x * sin(-data->p.move.ang_var) + data->p.rcast.p_dir_y * cos(-data->p.move.ang_var);
	data->p.rcast.fov_x = data->p.rcast.fov_x * cos(-data->p.move.ang_var) - data->p.rcast.fov_y * sin(-data->p.move.ang_var);
	data->p.rcast.fov_y = + old_fov_x * sin(-data->p.move.ang_var) + data->p.rcast.fov_y * cos(-data->p.move.ang_var);
	data->p.move.flag = 1;
}

void	rotate(t_data *data, int key)
{
	if (key == LEFT_ARROW)
	{
		rotate_left(data);
	}
	if (key == RIGHT_ARROW)
	{
		rotate_right(data);
	}
	printf("dir_x : %f | dir_y : %f\n", data->p.rcast.p_dir_x, data->p.rcast.p_dir_y);
}
