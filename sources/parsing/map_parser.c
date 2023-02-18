/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/18 17:58:03 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	printf("\n\n");
	while (data->map.map[++i])
	{
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'a')
				printf("\033[102m\033[1m%c\033[0m", data->map.map[i][j]);
			else if (data->map.map[i][j] == 'b')
				printf("\033[101m\033[1m%c\033[0m", data->map.map[i][j]);
			else if (data->map.map[i][j] == '0')
				printf("\033[104m\033[1m%c\033[0m", data->map.map[i][j]);
			else
				printf("%c", data->map.map[i][j]);
		}
		j = -1;
	}
}

/*Frees the allocated memory and exits the program*/
void	exit_message(char *message, t_data *data)
{
	free_split(data->parse.file);
	if (data->mlx->p_mlx)
		free(data->mlx->p_mlx);
	if (data->mlx->p_mlx_win)
		free(data->mlx->p_mlx_win);
	if (data->mlx->img)
		free(data->mlx->img);
	if (data->mlx->addr)
		free(data->mlx->addr);
	printf("%s\n", message);
	exit(0);
}
