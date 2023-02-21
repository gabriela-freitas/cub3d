/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:03:07 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/21 22:03:30 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dir(t_data *data)
{
	if (data->map.map[data->p.player_i][data->p.player_j] == 'E')
	{
		printf("\n⇉ player is facing East.\n");
		data->p.rcast.p_dir_x = 1;
		data->p.rcast.p_dir_y = 0;
		data->p.rcast.fov_x = 0;
		data->p.rcast.fov_y = -0.66;
	}
	else if (data->map.map[data->p.player_i][data->p.player_j] == 'W')
	{
		printf("\n⇇ player is facing West.\n");
		data->p.rcast.p_dir_x = -1;
		data->p.rcast.p_dir_y = 0;
		data->p.rcast.fov_x = 0;
		data->p.rcast.fov_y = 0.66;
	}
}

void	init_direction(t_data *data)
{
	if (data->map.map[data->p.player_i][data->p.player_j] == 'N')
	{
		printf("\n⇈ player is facing North.\n");
		data->p.rcast.p_dir_x = 0;
		data->p.rcast.p_dir_y = 1;
		data->p.angle = PI / 2;
		data->p.rcast.fov_x = 0.66;
		data->p.rcast.fov_y = 0.0;
	}
	else if (data->map.map[data->p.player_i][data->p.player_j] == 'S')
	{
		printf("\n⇊ player is facing South.\n");
		data->p.rcast.p_dir_x = 0;
		data->p.rcast.p_dir_y = -1;
		data->p.angle = 3 * PI / 2;
		data->p.rcast.fov_x = -0.66;
		data->p.rcast.fov_y = 0.;
	}
	init_dir(data);
}
