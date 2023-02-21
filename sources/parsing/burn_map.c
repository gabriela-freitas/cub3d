/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:10:48 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/21 21:59:21 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	adjacent_conditions(t_data *data, int i, int j, char nbr)
{
	if (j - 1 >= 0 && data->map.map[i][j - 1] == nbr)
		return (1);
	if (data->map.map[i][j + 1] && data->map.map[i][j + 1] == nbr)
		return (1);
	if (i - 1 >= 0 && data->map.map[i - 1][j] && \
	data->map.map[i - 1][j] == nbr)
		return (1);
	if (data->map.map[i + 1][j] && data->map.map[i + 1][j] == nbr)
		return (1);
	return (0);
}

// checks if it's a legal neighbor to burn.

int	legal_neighbors(t_data *data, int p_i, int p_j)
{
	if (p_j - 1 >= 0 && !(data->map.map[p_i][p_j - 1] == '1' || \
	data->map.map[p_i][p_j - 1] == '0' \
	|| data->map.map[p_i][p_j - 1] == 'a' || \
	data->map.map[p_i][p_j - 1] == 'b'))
		return (0);
	if (data->map.map[p_i][p_j + 1] && !(data->map.map[p_i][p_j + 1] == '1' \
	|| data->map.map[p_i][p_j + 1] == '0' \
	|| data->map.map[p_i][p_j + 1] == 'a' || data->map.map[p_i][p_j + 1] == \
	'b'))
		return (0);
	if (p_i - 1 >= 0 && data->map.map[p_i - 1][p_j] && \
	!(data->map.map[p_i - 1][p_j] == '1' || \
	data->map.map[p_i - 1][p_j] == '0' || data->map.map[p_i - 1][p_j] == 'a'\
	|| data->map.map[p_i - 1][p_j] == 'b'))
		return (0);
	if (data->map.map[p_i + 1][p_j] && !(data->map.map[p_i + 1][p_j] == '1' \
	|| data->map.map[p_i + 1][p_j] == '0' \
	|| data->map.map[p_i + 1][p_j] == 'a' || \
	data->map.map[p_i + 1][p_j] == 'b'))
		return (0);
	return (1);
}

// tells wether its to burn or found ilegal neighbors.

int	adjacent_burned(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '0' )
	{
		if (adjacent_conditions(data, i, j, 'b'))
		{
			if (legal_neighbors(data, i, j))
			{
				data->map.map[i][j] = 'a';
				return (1);
			}
			else
				return (-1);
		}
	}
	return (0);
}

// turns every 'a' to 'b' in the start of each burn.

void	starts_burns(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->map.map_height - 1)
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'a')
				data->map.map[i][j]++;
		}
	}
}

// burns the map

int	burn_map(t_data *data)
{
	int	ret;

	data->difus.i = 0;
	data->difus.flag = 0;
	starts_burns(data);
	while (data->difus.i <= data->map.map_height - 1)
	{
		data->difus.j = -1;
		while (data->map.map[data->difus.i][++data->difus.j])
		{
			ret = adjacent_burned(data, data->difus.i, data->difus.j);
			if (ret == 1)
			{
				data->map.map[data->difus.i][data->difus.j] = 'a';
				data->difus.flag++;
			}
			else if (ret == -1)
				return (0);
		}
		data->difus.i++;
	}
	data->difus.i = 0;
	return (1);
}
