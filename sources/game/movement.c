/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:27:25 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/20 20:24:21 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_data *data, int key)
{
	data->p.move.move_left = 1;
	data->p.move.move_right = 1;
	data->p.move.move_front = 1;
	data->p.move.move_back = 1;

	if (key == key_D && data->p.move.move_right == 1)
	{
		data->p.p_x -= data->p.rcast.fov_x * 0.1;
		data->p.p_y -= data->p.rcast.fov_y * 0.1;
	}
	if (key == key_A && data->p.move.move_left == 1)
	{
		data->p.p_x += data->p.rcast.fov_x * 0.1;
		data->p.p_y += data->p.rcast.fov_y * 0.1;
	}
	if (key == key_W && data->p.move.move_front == 1)
	{
		data->p.p_x += data->p.rcast.p_dir_x * 0.1;
		data->p.p_y += data->p.rcast.p_dir_y * 0.1;
	}
	if (key == key_S && data->p.move.move_back == 1)
	{
		data->p.p_x -= data->p.rcast.p_dir_x * 0.1;
		data->p.p_y -= data->p.rcast.p_dir_y * 0.1;
	}
}
