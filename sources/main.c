/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/25 19:44:22 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main_loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx.p_mlx, data->mlx.p_mlx_win, \
	data->mlx.img, 0, 0);
	return (0);
}

// int		parse_args(char **file); //gabi

int	parse_map(char *file_name, t_data *data)
{
	int	i;

	i = -1;
	data->map.map_height = 0;
	read_file(file_name, data);
	while (data->map.map[++i])
		data->map.map_height++;
	if (!map_test(data))
		exit_message("map is invalid", data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	data.mlx.p_mlx = NULL;
	parse_map(av[1], &data);
	if (!config_mlx(&data))
		exit_message("mlx error", &data);
	data.timers.time = 0;
	data.p.move.ang_var = -0.1;
	data.p.move.flag = 1;
	init_direction(&data);
	mlx_loop_hook(data.mlx.p_mlx, &main_loop, &data);
	// mathematics(&data);
	mlx_hook(data.mlx.p_mlx_win, KEY_PRESS, KeyPressMask, key_code, &data);
	mlx_put_image_to_window(data.mlx.p_mlx, data.mlx.p_mlx_win, \
	data.mlx.img, 0, 0);
	mlx_loop(data.mlx.p_mlx);
}
