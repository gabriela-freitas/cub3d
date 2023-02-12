/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:34:30 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_data *data)
{
	int	i = -1;
	int	j = -1;

	printf("\n\n");
	while (data->parse.map[++i])
	{
		while (data->parse.map[i][++j])
		{
			if (data->parse.map[i][j] == 'a')
				printf("\033[102m\033[1m%c\033[0m", data->parse.map[i][j]);
			else if (data->parse.map[i][j] == 'b')
				printf("\033[101m\033[1m%c\033[0m", data->parse.map[i][j]);
			else
				printf("%c", data->parse.map[i][j]);
		}
		j = -1;
	}
}

/*Frees the allocated memory and exits the program*/
void	exit_message(char *message, t_data *data)
{
	free_split(data->parse.file);
	printf("%s\n", message);
	exit(0);
}
