/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_starters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:19:55 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 18:49:44 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	starter(t_data *data)
{
	int	j;
	int	counter;

	j = -1;
	counter = 0;
	data->difus.i = 0;
	data->difus.max_i = 0;
	while (data->parse.map[data->difus.i][++j])
	{
		if (data->parse.map[data->difus.i][j] == '1')
			counter++;
	}
	if (counter == 1)
		data->difus.starting = 0;
	else if (counter > 2 && counter < 5)
		data->difus.starting = counter / 2;
	else if (counter > 4)
		data->difus.starting = counter / 4;
}

int	burn_first_row(t_data *data)
{
	int	j;
	int	flag;
	int	count;

	j = -1;
	flag = 0;
	count = 0;
	starter(data);
	while (data->parse.map[data->difus.i][++j])
	{
		if (data->parse.map[data->difus.i][j] == '1' && \
		count < data->difus.starting)
			count++;
		else if (data->parse.map[data->difus.i][j] == '1')
		{
			data->parse.map[data->difus.i][j]++;
			flag++;
		}
	}
	data->difus.max_i++;
	if (flag > 0)
		return (1);
	return (0);
}

int	burn_burned(t_data *data)
{
	int	j;
	int	flag;

	j = -1;
	flag = 0;
	data->difus.i = -1;
	while (++data->difus.i < 3)
	{
		while (data->parse.map[data->difus.i][++j])
		{
			if (data->parse.map[data->difus.i][j] == '2')
			{
				data->parse.map[data->difus.i][j]++;
				flag++;
			}
		}
		j = -1;
	}
	if (flag > 0)
		return (1);
	return (0);
}
