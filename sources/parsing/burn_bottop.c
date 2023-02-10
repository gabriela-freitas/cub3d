/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_bottop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:32:31 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 18:16:06 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// vou fazer pelo metodo de difusao : "vou acender fogo e ver se ja queimou".

// burns first row

int	adjacent_conditions2(t_data *data, int i, int j)
{
	if (i - 1 >= 0 && data->parse.map[i - 1][j] && \
	data->parse.map[i - 1][j] == '2')
		return (1);
	else if (data->parse.map[i][j - 1] && \
	data->parse.map[i][j - 1] == '2')
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
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] \
	&& data->parse.map[i + 1][j + 1] == '2')
		return (1);
	else if (data->difus.flag == 0 && i - 1 >= 0 && \
	data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '2')
		return (1);
	else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && \
	data->parse.map[i - 1][j + 1] == '2')
		return (1);
	return (0);
}

// finds burned spots

int	adjacent_burned2(t_data *data, int i, int j)
{
	if (data->parse.map[i][j] == '1')
	{
		if (adjacent_conditions2(data, i, j))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	handle_closeness(t_data *data)
{
	if (finding_closeness(data, data->difus.i, data->difus.j) == 1)
	{
		data->difus.flag = 0;
		data->parse.map[data->difus.i][data->difus.j] = '2';
		print_map(data);
		return (2);
	}
	else if (finding_closeness(data, data->difus.i, data->difus.j) == 2)
	{
		data->difus.flag++;
		data->parse.map[data->difus.i][data->difus.j] = '3';
		print_map(data);
	}
	return (0);
}

// burns linked spots top to bottom

int	rev_burn_map(t_data *data)
{
	data->difus.i = 0;
	data->difus.flag = 0;
	data->difus.max_i = data->difus.size_map - 1;
	while (data->difus.i <= data->difus.max_i)
	{
		data->difus.j = -1;
		while (data->parse.map[data->difus.i][++data->difus.j])
		{
			if (handle_closeness(data))
				return (2);
			if (adjacent_burned2(data, data->difus.i, data->difus.j))
			{
				data->parse.map[data->difus.i][data->difus.j] = '2';
				data->difus.flag++;
				print_map(data);
			}
		}
		data->difus.i++;
	}
	if (data->difus.flag > 0)
		return (1);
	return (0);
}
