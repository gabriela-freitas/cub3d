/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:32:31 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 15:36:44 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// vou fazer pelo metodo de difusao : "vou acender fogo e ver se ja queimou".

// burns first row

int	burn_first_row(t_data *data)
{
	int	j;
	int	flag;
	int	count;

	j = -1;
	flag = 0;
	count = 0;
	data->difus.i = 0;
	data->difus.max_i = 0;
	while (data->parse.map[data->difus.i][++j])
	{
		if (data->parse.map[data->difus.i][j] == '1')
			count++;
	}
	if (count == 1)
		data->difus.starting = 0;
	else
		data->difus.starting = count / 2;
	printf("\ndata->difus.starting : %d\n", data->difus.starting);
	j = -1;
	count = 0;
	while (data->parse.map[data->difus.i][++j])
	{
		if (data->parse.map[data->difus.i][j] == '1' && count < data->difus.starting)
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
	data->difus.i = - 1;
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

// finds burned spots

int adjacent_burned(t_data *data, int i, int j)
{
	if(data->parse.map[i][j] == '1')
	{
		if (data->difus.first_one == -1 && i != data->difus.size_map - 1)
			data->difus.first_one = j;
		else
		{
			if (j != data->difus.first_one && i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == '2') //top
				return (1);
			else if (i != (data->difus.size_map - 1) && data->parse.map[i][j - 1] && data->parse.map[i][j - 1] == '2') //left
				return (1);
			else if (i!= 0 && data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == '2') //right
				return (1);
			else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == '2') //down
				return (1);
			else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] && data->parse.map[i + 1][j - 1] == '2') //down + left
				return (1);
			else if (i!= 0 && i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '2') //down + right
				return (1);
			else if (i - 1 >= 0 && i != (data->difus.size_map - 1) && data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '2') //top + left
				return (1);
			else if (i - 1 != 0 && i - 1 >= 0 && data->parse.map[i - 1][j + 1] && data->parse.map[i - 1][j + 1] == '2') //top + right
				return (1);
		}
	}
	return (0);
}

int adjacent_burned2(t_data *data, int i, int j)
{
	if(data->parse.map[i][j] == '1')
	{
			if (i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == '2') //top
				return (1);
			else if (data->parse.map[i][j - 1] && data->parse.map[i][j - 1] == '2') //left
				return (1);
			else if (i != 0 && data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == '2') //right
				return (1);
			else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == '2') //down
				return (1);
			else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] && data->parse.map[i + 1][j - 1] == '2') //down + left
				return (1);
			else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '2') //down + right
				return (1);
			else if (i - 1 >= 0 && data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '2') //top + left
				return (1);
			else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && data->parse.map[i - 1][j + 1] == '2') //top + right
				return (1);
	}
	return (0);
}

// burns linked spots top to bottom

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

int	finding_closeness(t_data *data, int i, int j)
{
	int	jay;

	jay = -1;
	while (data->parse.map[data->difus.i][++jay])
	{
		if (data->parse.map[data->difus.i][jay] == '2')
		{
			if (data->parse.map[data->difus.i][jay + 1] && data->parse.map[data->difus.i][jay + 1] == '2')
				continue ;
			else if (data->parse.map[data->difus.i][jay + 1] && data->parse.map[data->difus.i][jay + 1] == '1')
			{
				jay++;
				break ;
			}
			else
			{
				break ;
			}
		}
	}
	if (data->parse.map[i][j] == '1' && jay == j)
	{
		if (i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == '3') //top
			return (1);
		else if (data->parse.map[i][j - 1] && data->parse.map[i][j - 1] == '3') //left
			return (1);
		else if (data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == '3') //right
			return (1);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == '3') //down
			return (1);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] && data->parse.map[i + 1][j - 1] == '3') //down + left
			return (1);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '3') //down + right
			return (1);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '3') //top + left
			return (1);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && data->parse.map[i - 1][j + 1] == '3') //top + right
			return (1);
	}
	else if (data->parse.map[i][j] == '2')
	{
		if (i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == '3') //top
			return (2);
		else if (data->parse.map[i][j - 1] && data->parse.map[i][j - 1] == '3') //left
			return (2);
		else if (data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == '3') //right
			return (2);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == '3') //down
			return (2);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] && data->parse.map[i + 1][j - 1] == '3') //down + left
			return (2);
		else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '3') //down + right
			return (2);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '3') //top + left
			return (2);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && data->parse.map[i - 1][j + 1] == '3') //top + right
			return (2);
	}
	return (0);
}

// burns linked spots top to bottom

int	rev_burn_map(t_data *data)
{
	if (data->difus.max_i > 0)
		data->difus.max_i--;
	data->difus.flag = 0;
	data->difus.i = data->difus.size_map - 1;
	while (data->difus.i >= data->difus.max_i)
	{
		data->difus.j = -1;
		while (data->parse.map[data->difus.i][++data->difus.j])
		{
			if (finding_closeness(data, data->difus.i, data->difus.j) == 1)
			{
				data->difus.flag = 0;
				data->parse.map[data->difus.i][data->difus.j] = '2';
				print_map(data);
				printf("\n✅ map is closed.\n");
				return (0);
			}
			else if (finding_closeness(data, data->difus.i, data->difus.j) == 2)
			{
				data->difus.flag++;
				data->parse.map[data->difus.i][data->difus.j] = '3';
				print_map(data);
			}
			if (adjacent_burned2(data, data->difus.i, data->difus.j))
			{
				data->parse.map[data->difus.i][data->difus.j] = '2';
				data->difus.flag++;
				print_map(data);
			}
		}
		data->difus.i--;
	}
	if (data->difus.flag > 0)
		return (1);
	return (0);
}
