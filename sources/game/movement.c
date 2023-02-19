/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:27:25 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/19 20:08:24 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_data *data, int key)
{
	if (data->p.angle >= PI / 2 && data->p.angle <= 3 * PI / 2)
	{
		if (key == key_D)
		{
			data->p.p_x += 0.1 * sin(data->p.angle);
			data->p.p_y += 0.1 * cos(data->p.angle);
		}
		if (key == key_A)
		{
			data->p.p_x -= 0.1 * sin(data->p.angle);
			data->p.p_y -= 0.1 * cos(data->p.angle);
		}
		if (key == key_W)
		{
			data->p.p_x += 0.1 * cos(data->p.angle);
			data->p.p_y += 0.1 * sin(data->p.angle);
		}
		if (key == key_S)
		{
			data->p.p_x -= 0.1 * cos(data->p.angle);
			data->p.p_y -= 0.1 * sin(data->p.angle);
		}
	}
	else
	{
		if (key == key_D)
		{
			data->p.p_x -= 0.1 * sin(data->p.angle);
			data->p.p_y -= 0.1 * cos(data->p.angle);
		}
		if (key == key_A)
		{
			data->p.p_x += 0.1 * sin(data->p.angle);
			data->p.p_y += 0.1 * cos(data->p.angle);
		}
		if (key == key_W)
		{
			data->p.p_x += 0.1 * cos(data->p.angle);
			data->p.p_y += 0.1 * sin(data->p.angle);
		}
		if (key == key_S)
		{
			data->p.p_x -= 0.1 * cos(data->p.angle);
			data->p.p_y -= 0.1 * sin(data->p.angle);
		}
	}
	printf("angle : %f\n", data->p.angle);
}