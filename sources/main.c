/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/17 19:42:30 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// int		parse_args(char **file); //gabi

int	parse_map(char *file_name, t_data *data)
{
	int	i;

	i = -1;
	data->map.map_height = 0;
	read_file(file_name, data);
	get_file_info(data);
	//necessario saber a cor de cada lado ou textura
	data->draw.n = 255; //blue
	data->draw.s = 255*65536; //red
	data->draw.e = 255*255; // green
	data->draw.w = 255*65536 + 255; //pink
	while (data->map.map[++i])
		data->map.map_height++;

	if (!map_test(data))
		return (0);
	return (1);
}

// int	main(int ac, char **av)
// {
// 	t_data	data;

// 	if (ac > 1)
// 	{
// 		parse_map(av[1], &data);
// 		mathematics(&data);
// 	}
// }

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_data	data;

	if (ac > 1)
		parse_map(av[1], &data);
	mlx.p_mlx = mlx_init();
	if (!mlx.p_mlx) //TO-DO REMEMBER TO FREE THIS LATER!
		return (0);
	mlx.p_mlx_win = mlx_new_window(mlx.p_mlx, WIN_W, WIN_H, "Cub3D");
	if (!mlx.p_mlx_win) //and this
		return (0);
	mlx.img = mlx_new_image(mlx.p_mlx,  WIN_W, WIN_H);
	if (!mlx.img) //and this
		return (0);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	if (!mlx.addr) //and this
		return (0);
	mlx_hook(mlx.p_mlx_win, DESTROY_NOTIFY, ButtonPressMask, close_win, NULL);
	mlx_hook(mlx.p_mlx_win, KEY_PRESS, KeyPressMask, key_code, NULL);
	data.mlx = &mlx;
	mathematics(&data);
	// print_square(&mlx, 32, 64, 120, 0x00FF0000);
	// print_square(&mlx, 32, 64, 60, 0x00FFFF00);
	mlx_put_image_to_window(mlx.p_mlx, mlx.p_mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.p_mlx);
}

