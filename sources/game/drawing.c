/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:48:46 by gafreita          #+#    #+#             */
/*   Updated: 2023/03/07 17:19:00 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	calculate_y(t_data *data, int i);

void	draw_ray(t_data *data, int nbr_rays, int x, float Wallx)
{
	int	i;
	int	txt;

	i = -1;
	txt = data->colors[C];
	while (++i < WIN_H)
	{
		if (i >= data->p.rcast.draw_start && i < data->p.rcast.draw_end)
		{
			if (data->p.rcast.side_hit)
			{
				txt = my_mlx_pixel_get(&data->wall[!(data->p.rcast.ray_y > 0)], \
				Wallx, calculate_y(data, i));
			}
			else
			{
				txt = my_mlx_pixel_get(
						&data->wall[!(data->p.rcast.ray_x > 0) + 2],
						Wallx, calculate_y(data, i));
			}
		}
		if (i == data->p.rcast.draw_end)
			txt = data->colors[F];
		my_mlx_pixel_put(&data->mlx, nbr_rays - x, i, txt);
	}
}

static float	calculate_y(t_data *data, int i)
{
	return ((float)(i - data->p.rcast.draw_start) /
		(data->p.rcast.draw_end - data->p.rcast.draw_start) * 64);
}
