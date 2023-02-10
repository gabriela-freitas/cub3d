/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:32:45 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 00:37:48 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int line_burned(t_data *data, int i, int j)
{
	if(data->parse.map[i][j] == '4')
	{
		if (j > 1 && data->parse.map[i][j - 1] && data->parse.map[i][j - 1] == '4') //left
			return (1);
		else if (data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == '4') //right
			return (1);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == '4') //top
			return (3);
		else if (!(j == 0 && i != data->difus.max_i -1) && data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == '4') //down
			return (2);
		else if (data->parse.map[i + 1][j - 1] && data->parse.map[i + 1][j - 1] == '4') //down + left
			return (2);
		else if (data->parse.map[i + 1][j + 1] && data->parse.map[i + 1][j + 1] == '4') //down + right
			return (2);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j - 1] && data->parse.map[i - 1][j - 1] == '4') //top + left
			return (3);
		else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && data->parse.map[i - 1][j + 1] == '4') //down + left
			return (3);
	}
	return (0);
}

void	burn_corners(t_data *data, int index, int j)
{
	int	jay;
	int	flag;

	jay = j;
	flag = 1;
	data->parse.map[index][j] = '4';
	while(data->parse.map[index][j])
		j++;
	while(data->parse.map[index][--j])
	{
		if (data->parse.map[index][j] == '4' && \
		data->parse.map[index][j] != data->parse.map[index][jay])
		{
			data->parse.map[index][j] = '4';
			flag++;
		}
	}
	while (flag < 2)
	{
		index++;
		while(data->parse.map[index][j])
		j++;
		while(data->parse.map[index][--j])
		{
			if (data->parse.map[index][j] == '4' && \
			data->parse.map[index][j] != data->parse.map[index][jay])
			{
				data->parse.map[index][j] = '4';
				flag++;
			}
		}
	}
}

int	burn_line(t_data *data, int index, int j)
{
	data->difus.ret = 0;
	data->difus.flag = 1;
	burn_corners(data, index, j);
	while (data->difus.flag > 0)
	{
		data->difus.j = -1;
		data->difus.flag = 0;
		while (data->parse.map[index][++data->difus.j])
		{
			data->difus.ret = line_burned(data, index, data->difus.j);
			if (data->difus.ret == 1)
			{
				data->parse.map[index][data->difus.j] = '4';
				data->difus.flag++;
			}
			else if (data->difus.ret == 2)
			{
				data->parse.map[index][data->difus.j] = '4';
				data->difus.flag++;
				index++;
				break ;
			}
			else if(data->difus.ret == 3)
			{
				data->parse.map[index][data->difus.j] = '4';
				data->difus.flag++;
				index--;
				break ;
			}
		}
	}
	index = 0;
	if (data->difus.max_i < data->difus.size_map - 1)
		data->difus.max_i++;
	if (data->difus.flag > 0)
		return (1);
	return (0);
}

// checks if line is linked

int	linked_line(t_data *data, int index)
{
	int	j;
	int	flag;

	j = -1;
	flag = 0;
	while (data->parse.map[index][++j])
	{
		if (data->parse.map[index][j] == '3')
		{
			burn_line(data, index, j);
			while (data->parse.map[index][j])
			{
				if ( data->parse.map[index][j] == ' ' || \
				data->parse.map[index][j] == 9 || data->parse.map[index][j] == 10)
					flag++;
				else
					return (0);
				j++;
			}
			break ;
		}
	}
	if (flag > 0)
		return (1);
	return (0);
}

