/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:27:25 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/21 21:55:11 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// tentativa de colisao

void	move_sides(t_data *data, int key)
{
	int	i;
	int	j;

	if (key == key_A)
	{
		i = data->p.p_y + data->p.rcast.fov_y * 0.1;
		j = data->p.p_x + data->p.rcast.fov_x * 0.1;
		if (data->map.map[data->p.player_i][j] != '1')
			data->p.p_x += data->p.rcast.fov_x * 0.1;
		if (data->map.map[i][data->p.player_j] != '1')
			data->p.p_y += data->p.rcast.fov_y * 0.1;
	}
	if (key == key_D)
	{
		i = data->p.p_y - data->p.rcast.fov_y * 0.1;
		j = data->p.p_x - data->p.rcast.fov_x * 0.1;
		if (data->map.map[data->p.player_i][j] != '1')
			data->p.p_x -= data->p.rcast.fov_x * 0.1;
		if (data->map.map[i][data->p.player_j] != '1')
			data->p.p_y -= data->p.rcast.fov_y * 0.1;
	}
}

void	move(t_data *data, int key)
{
	int	i;
	int	j;

	if (key == key_W)
	{
		i = data->p.p_y + data->p.rcast.p_dir_y * 0.15;
		j = data->p.p_x + data->p.rcast.p_dir_x * 0.15;
		if (data->map.map[data->p.player_i][j] != '1')
			data->p.p_x += data->p.rcast.p_dir_x * 0.15;
		if (data->map.map[i][data->p.player_j] != '1')
			data->p.p_y += data->p.rcast.p_dir_y * 0.15;
	}
	if (key == key_S)
	{
		i = data->p.p_y - data->p.rcast.p_dir_y * 0.1;
		j = data->p.p_x - data->p.rcast.p_dir_x * 0.15;
		if (data->map.map[data->p.player_i][j] != '1')
			data->p.p_x -= data->p.rcast.p_dir_x * 0.1;
		if (data->map.map[i][data->p.player_j] != '1')
			data->p.p_y -= data->p.rcast.p_dir_y * 0.1;
	}
	move_sides(data, key);
}
