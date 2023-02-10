/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_topbot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:10:48 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 16:43:30 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	adjacent_conditions(t_data *data, int i, int j)
{
	if (j != data->difus.first_one && i - 1 >= 0 && data->parse.map[i - 1][j] \
	&& data->parse.map[i - 1][j] == '2')
		return (1);
	else if (i != (data->difus.size_map - 1) && data->parse.map[i][j - 1] \
	&& data->parse.map[i][j - 1] == '2')
		return (1);
	else if (i != 0 && data->parse.map[i][j + 1] && \
	data->parse.map[i][j + 1] == '2')
		return (1);
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] \
	&& data->parse.map[i + 1][j] == '2')
		return (1);
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] \
	&& data->parse.map[i + 1][j - 1] == '2')
		return (1);
	else if (i != 0 && i + 1 < data->difus.size_map && \
	data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '2')
		return (1);
	else if (i - 1 >= 0 && i != (data->difus.size_map - 1) \
	&& data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '2')
		return (1);
	else if (i - 1 != 0 && i - 1 >= 0 && data->parse.map[i - 1][j + 1] \
	&& data->parse.map[i - 1][j + 1] == '2')
		return (1);
	return (0);
}

int	adjacent_burned(t_data *data, int i, int j)
{
	if (data->parse.map[i][j] == '1')
	{
		if (data->difus.first_one == -1 && i != data->difus.size_map - 1)
			data->difus.first_one = j;
		else
		{
			if (adjacent_conditions(data, i, j))
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

int	burn_map(t_data *data)
{
	data->difus.flag = 0;
	while (data->difus.i <= data->difus.max_i)
	{
		data->difus.j = -1;
		data->difus.first_one = -1;
		while (data->parse.map[data->difus.i][++data->difus.j])
		{
			if (adjacent_burned(data, data->difus.i, data->difus.j))
			{
				data->parse.map[data->difus.i][data->difus.j] = '2';
				data->difus.flag++;
				print_map(data);
			}
		}
		data->difus.i++;
	}
	data->difus.i = 0;
	if (data->difus.max_i < data->difus.size_map - 1)
		data->difus.max_i++;
	if (data->difus.flag > 0)
		return (1);
	return (0);
}
