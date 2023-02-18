/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/18 17:59:40 by gafreita         ###   ########.fr       */
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
	t_data	data;

	if (ac == 1)
		return (0);
	parse_map(av[1], &data);
	data.mlx = config_mlx();
	if (!data.mlx)
		exit_message("mlx error", &data);
	mathematics(&data);
	mlx_put_image_to_window(data.mlx->p_mlx, data.mlx->p_mlx_win, data.mlx->img, 0, 0);
	mlx_loop(data.mlx->p_mlx);
}

