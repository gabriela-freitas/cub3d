/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/11 20:57:38 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int		parse_args(char **file); //gabi
int		check_map(char **map); //diogo

void	parse_map(char *file_name, t_data *data)
{
	read_file(file_name, data);
	get_file_info(data);
	// int i;
	// i = -1;
	// while (data->parse.file[++i])
	// 	printf("%s", data->parse.file[i]);
	// i = -1;
	// printf("\n#################################\n\n");
	// while (data->parse.map[++i])
	// 	printf("%s", data->parse.map[i]);
	// printf("\n#################################\n\n%d", data->parse.size_map);
}


int	main(int ac, char **av)
{
	t_data	data;

	//TO-DO: remember to check args number etc
	if (ac > 1)
	{
		parse_map(av[1], &data);
		print_map(&data);
        // gabi o size_map nao esta bem atualizado
        data.difus.size_map = 7;
		map_test(&data);
	}
	//free_split(data.parse.file);
	// comeca a brincadeira
	// imagens + window + por tudo com tamanhos que queremos + hooks
	// matematica para projectar
}
