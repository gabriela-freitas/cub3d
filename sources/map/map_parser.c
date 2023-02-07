/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/07 19:56:12 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_message(char *message)
{
	printf("%s\n", message);
	exit(0);
}

/*Check if its a valid file name and a valid map
And saves the map*/

void	parse_map(t_data *data, char *file_name)
{
	data->map_fd = open(file_name, O_RDONLY);
	if (data->map_fd == -1)
		exit_message("Map file not found\n");
	//init_variables();
	if (check_map(data))
		printf("o mapa e valido\n");
	else
		printf("o mapa e invalido\n");
}
