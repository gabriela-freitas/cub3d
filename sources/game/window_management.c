/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:48:11 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/19 18:49:30 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*It' triggered when the users presses a key
	Deals with movements (W, S, D, A) and (right and left arrow)
	and closing the window when ESC is pressed*/
int	key_code(int keycode, t_data *data)
{
	if (keycode == key_ESC)
		exit(0);
	if (keycode == key_D)
	{
		data->p.p_x += 0.2;
		mathematics(data);
	}
	printf("key: %d\n", keycode);
	return (1);
}

/*It's triggered when the user clicks on the window's exit button*/
int	close_win(t_data *data)
{
	exit_message("thank you for playing!", data);
	return (1);
}

void	print_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mlx_pixel_put(mlx, x + i, y + j, color);
	}
}


t_mlx *config_mlx(t_data *data)
{
	static t_mlx	mlx;

	mlx.p_mlx = mlx_init();
	if (!mlx.p_mlx)
		return (NULL);
	mlx.p_mlx_win = mlx_new_window(mlx.p_mlx, WIN_W, WIN_H, "Cub3D");
	if (!mlx.p_mlx_win)
		return (NULL);
	mlx.img = mlx_new_image(mlx.p_mlx,  WIN_W, WIN_H);
	if (!mlx.img)
		return (NULL);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	if (!mlx.addr)
		return (NULL);
	mlx_hook(mlx.p_mlx_win, DESTROY_NOTIFY, ButtonPressMask, close_win, data);
	return (&mlx);
}

void	draw_ray(t_data *data, int nbr_rays, int x)
{
	int	i;
	int	color;

	i = -1;
	color = 0x2F323F;
	while (++i < WIN_H)
	{
		if (data->p.rcast.side_hit)
		{
			if (i == data->p.rcast.draw_start)
				color =  0x943241;
			if (i == data->p.rcast.draw_end)
				color =  0x1263617;
		}
		else
		{
			if (i == data->p.rcast.draw_start)
			color = 255*65536+255*256;
			if (i == data->p.rcast.draw_end)
				color =  0x1263617;
		}
		my_mlx_pixel_put(data->mlx, nbr_rays - x, i, color);
	}
}
