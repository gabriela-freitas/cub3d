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

int	adjacent_conditions(t_data *data, int i, int j, char nbr)
{
    if (j - 1 >= 0 && data->parse.map[i][j - 1] == nbr)    //left
        return (1);
    if (data->parse.map[i][j + 1] && data->parse.map[i][j + 1] == nbr)  //right
        return (1);
    if (i - 1 >= 0 && data->parse.map[i - 1][j] && data->parse.map[i - 1][j] == nbr) //top
        return (1);
    if (data->parse.map[i + 1][j] && data->parse.map[i + 1][j] == nbr) //bot
        return (1);
    return (0);
}

int legal_neighbors(t_data *data, int p_i, int p_j)
{
    if (p_j - 1 >= 0 && !(data->parse.map[p_i][p_j - 1] == '1' || data->parse.map[p_i][p_j - 1] == '0' \
    || data->parse.map[p_i][p_j - 1] == 'a' || data->parse.map[p_i][p_j - 1] == 'b'))
        return (0);
    if (data->parse.map[p_i][p_j + 1] && !(data->parse.map[p_i][p_j + 1] == '1' || data->parse.map[p_i][p_j + 1] == '0' \
    || data->parse.map[p_i][p_j + 1] == 'a' || data->parse.map[p_i][p_j + 1] == 'b'))
        return (0);
    if (p_i - 1 >= 0 && data->parse.map[p_i - 1][p_j] && !(data->parse.map[p_i - 1][p_j] == '1' || data->parse.map[p_i - 1][p_j] == '0' \
    || data->parse.map[p_i - 1][p_j] == 'a' || data->parse.map[p_i - 1][p_j] == 'b'))
        return (0);
    if (data->parse.map[p_i + 1][p_j] && !(data->parse.map[p_i + 1][p_j] == '1' || data->parse.map[p_i + 1][p_j] == '0' \
    || data->parse.map[p_i + 1][p_j] == 'a' || data->parse.map[p_i + 1][p_j] == 'b'))
        return (0);
    return (1);
}

int	adjacent_burned(t_data *data, int i, int j) {
    if (data->parse.map[i][j] == '0' )
    {
        if (adjacent_conditions(data, i, j, 'b'))
        {
            if (legal_neighbors(data, i, j))
            {
                data->parse.map[i][j] = 'a';
                return (1);
            }
            else
                return (-1);
        }
    }
	return (0);
}

void     starts_burns(t_data *data)
{
    int i;
    int j;

    i = -1;
    printf("%d\n", data->difus.size_map);
    while (++i <= data->difus.size_map - 1)
    {
        j= -1;
        while (data->parse.map[i][++j])
        {
            if (data->parse.map[i][j] == 'a')
                data->parse.map[i][j]++;
        }
    }
}

int	burn_map(t_data *data)
{
    int ret;

    data->difus.i = 0;
	data->difus.flag = 0;
    starts_burns(data);
    print_map(data);
	while (data->difus.i <= data->difus.size_map - 1)
	{
		data->difus.j = -1;
		while (data->parse.map[data->difus.i][++data->difus.j])
		{
            ret = adjacent_burned(data, data->difus.i, data->difus.j);
			if (ret == 1)
			{
				data->parse.map[data->difus.i][data->difus.j] = 'a';
				data->difus.flag++;
			}
            else if (ret == -1)
                return (0);
		}
		data->difus.i++;
	}
    print_map(data);
	data->difus.i = 0;
    return (1);
}
