/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:48:11 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/26 19:54:44 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_wall *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8))));
}

/*It' triggered when the users presses a key
	Deals with movements (W, S, D, A) and (right and left arrow)
	and closing the window when ESC is pressed*/

int	key_code(int keycode, t_data *data)
{
	if (keycode == key_ESC)
		exit_message("thank you for playing!", data);
	else
	{
		if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
			rotate(data, keycode);
		else
			move(data, keycode);
		mathematics(data);
	}
	return (1);
}

/*It's triggered when the user clicks on the window's exit button*/
int	close_win(t_data *data)
{
	exit_message("thank you for playing!", data);
	return (1);
}

int	config_mlx(t_data *data)
{
	data->mlx.p_mlx = mlx_init();
	if (!data->mlx.p_mlx)
		return (0);
	get_file_info(data);
	data->mlx.p_mlx_win = mlx_new_window(data->mlx.p_mlx,
			WIN_W, WIN_H, "Cub3D");
	if (!data->mlx.p_mlx_win)
		return (0);
	data->mlx.img = mlx_new_image(data->mlx.p_mlx, WIN_W, WIN_H);
	if (!data->mlx.img)
		return (0);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	if (!data->mlx.addr)
		return (0);
	mlx_hook(data->mlx.p_mlx_win, DESTROY_NOTIFY,
		ButtonPressMask, close_win, data);
	return (1);
}
