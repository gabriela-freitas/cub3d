/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/10 18:12:18 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//char	**read_file(char *file_path); //gabi
//int		parse_args(char **file); //gabi
//int		check_map(char **map); //diogo

/* void	parse_map(t_data *data)
{
	// vai receber **read_file
	// vai receber parse_args
	// vai receber check_map
} */

int	main(void)
{
	t_data	data;

	create_test_map(&data);
	print_map(&data);
	map_test(&data);
}
	// comeca a brincadeira
	// imagens + window + por tudo com tamanhos que queremos + hooks
	// matematica para projectar
