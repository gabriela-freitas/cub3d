/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:00:28 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/13 03:12:35 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->parse.map[++i])
	{
		while (data->parse.map[i][j])
		{
			if (data->parse.map[i][j] == 'N' || data->parse.map[i][j] == 'S' \
			|| data->parse.map[i][j] == 'E' || data->parse.map[i][j] == 'W' \
			|| data->parse.map[i][j] == '1' || data->parse.map[i][j] == '0' \
			|| data->parse.map[i][j] == ' ' || data->parse.map[i][j] == 9 \
			|| data->parse.map[i][j] == '\n')
				j++;
			else
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	one_position(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (data->parse.map[++i])
	{
		j = -1;
		while (data->parse.map[i][++j])
		{
			if (data->parse.map[i][j] == 'N' || data->parse.map[i][j] == 'S' \
			|| data->parse.map[i][j] == 'E' || data->parse.map[i][j] == 'W')
			{
				data->difus.player_i = i;
                data->difus.player_j = j;
				flag++;
			}
		}
	}
	if (flag == 1)
		return (1);
	else
		return (0);
}


int	burn_adj_posits(t_data *data, int p_i, int p_j)
{
	if (p_j - 1 >= 0 && data->parse.map[p_i][p_j - 1] == '0')
		data->parse.map[p_i][p_j - 1] = 'a';
	else if (p_j - 1 >= 0 && data->parse.map[p_i][p_j - 1] != '1')
		return (0);
	if (data->parse.map[p_i][p_j + 1] && data->parse.map[p_i][p_j + 1] == '0')
		data->parse.map[p_i][p_j + 1] = 'a';
	else if (data->parse.map[p_i][p_j + 1] && \
	data->parse.map[p_i][p_j + 1] != '1')
		return (0);
	if (p_i - 1 >= 0 && data->parse.map[p_i - 1][p_j] \
	&& data->parse.map[p_i - 1][p_j] == '0')
		data->parse.map[p_i - 1][p_j] = 'a';
	else if (p_i - 1 >= 0 && data->parse.map[p_i - 1][p_j] \
	&& data->parse.map[p_i - 1][p_j] != '1')
		return (0);
	if (data->parse.map[p_i + 1][p_j] && \
	data->parse.map[p_i + 1][p_j] == '0')
		data->parse.map[p_i + 1][p_j] = 'a';
	else if (data->parse.map[p_i + 1][p_j] && \
	data->parse.map[p_i + 1][p_j] != '1')
		return (0);
	data->difus.flag++;
	return (1);
}

int	closed_map(t_data *data)
{
	int	p_i;
	int	p_j;

	data->difus.flag = 1;
	p_i = data->difus.player_i;
	p_j = data->difus.player_j;
	if (!burn_adj_posits(data, p_i, p_j))
	{
		printf ("Invalid Map.\n");
		return (0);
	}
	while (data->difus.flag > 0)
	{
		if (!burn_map(data))
		{
			printf("\nBurn top to bottom has stoped.\n");
			return (0);
		}
	}
	print_map(data);
	return (1);
}

int	map_test(t_data *data)
{
	if (!check_char(data))
	{
		printf("\n❌ Wrong character used.\n");
		return (0);
	}
	if (!one_position(data))
	{
		printf("\n❌ Not one player position.\n");
		return (0);
	}
	if (!closed_map(data))
	{
		printf("\n❌ Map is not closed.\n");
		return (0);
	}
	else
	{
		printf("\n✅ Map is closed.");
		printf("\n✅ All characters are legal.");
		printf("\n✅ 1 and only player position. \n");
	}
	return (1);
}
