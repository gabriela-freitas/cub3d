/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:42:15 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		parse_args(char **file); //gabi
int		check_map(char **map); //diogo

void	parse_map(char *file_name, t_data *data)
{
	read_file(file_name, data);
	//tests to check if the map is returning right
	int i;
	i = -1;

	while (data->parse.map[++i])
		printf("%s", data->parse.map[++i]);
}


int	main(int ac, char **av)
{
	t_data	data;

	//TO-DO: remember to check args number etc
	if (ac > 1)
		parse_map(av[1], &data);
	// comeca a brincadeira
	// imagens + window + por tudo com tamanhos que queremos + hooks
	// matematica para projectar
}
