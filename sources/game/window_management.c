/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:48:11 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/17 19:06:39 by gafreita         ###   ########.fr       */
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
int	key_code(int keycode)
{
	if (keycode == key_ESC)
		exit(0);
	printf("key: %d\n", keycode);
	return (1);
}

/*It's triggered when the user clicks on the window's exit button*/
int	close_win(void)
{
	exit(0);
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
