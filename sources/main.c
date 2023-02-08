/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:13:54 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**read_file(char *file_path); //gabi
int		parse_args(char **file); //gabi
int		check_map(char **map); //diogo

void	parse_map(t_data *data)
{
	// vai receber **read_file
	// vai receber parse_args
	// vai receber check_map
}


int	main()
{
	t_data	data;

	parse_map(&data);
	// comeca a brincadeira
	// imagens + window + por tudo com tamanhos que queremos + hooks
	// matematica para projectar
}
