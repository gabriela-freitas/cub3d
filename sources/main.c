/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/13 23:41:55 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int		parse_args(char **file); //gabi

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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		parse_map(av[1], &data);
		mathematics(&data);
	}
}
