/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/10 18:52:05 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_test_map(t_data *data)
{
	int count = 0;
	int	i = -1;
	char *line;
	int	fd = open("/home/ratinhosujo/cub3d/maps/test_map5.cub", O_RDONLY);
	data->parse.map = (char **)malloc(8 * sizeof(char *));
	data->difus.size_map = 7;
	data->parse.map[7] = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[++i]);
		data->parse.map[count] = (char *)malloc(i * sizeof(char));
		data->parse.map[count][i - 1] = 0;
		i = -1;
		while (line[++i])
			data->parse.map[count][i] = line[i];
		count++;
		i = -1;
		free(line);
		line = get_next_line(fd);
	}
}

void	print_map(t_data *data)
{
	int	i = -1;
	int	j = -1;

	printf("\n\n");
	while (data->parse.map[++i])
	{
		while (data->parse.map[i][++j])
		{
			if (data->parse.map[i][j] == '2')
				printf("\033[102m\033[1m%c\033[0m", data->parse.map[i][j]);
			else if (data->parse.map[i][j] == '3')
				printf("\033[101m\033[1m%c\033[0m", data->parse.map[i][j]);
			else
				printf("%c", data->parse.map[i][j]);
		}
		j = -1;
	}
}

void	exit_message(char *message)
{
	//FREE MAP
	printf("%s\n", message);
	exit(0);
}
