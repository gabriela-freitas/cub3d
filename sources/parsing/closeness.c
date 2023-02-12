/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:56:58 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 18:11:08 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	finding_closeness1(t_data *data, int i, int j)
{
	if (i - 1 >= 0 && data->parse.map[i - 1][j] && \
		data->parse.map[i - 1][j] == '3')
		return (1);
	else if (data->parse.map[i][j - 1] && \
	data->parse.map[i][j - 1] == '3')
		return (1);
	else if (data->parse.map[i][j + 1] && \
	data->parse.map[i][j + 1] == '3')
		return (1);
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j] \
	&& data->parse.map[i + 1][j] == '3')
		return (1);
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j - 1] \
	&& data->parse.map[i + 1][j - 1] == '3')
		return (1);
	else if (i + 1 < data->difus.size_map && data->parse.map[i + 1][j + 1] \
	&& data->parse.map[i + 1][j + 1] == '3')
		return (1);
	else if (i - 1 >= 0 && data->parse.map[i - 1][j - 1] && \
	data->parse.map[i - 1][j - 1] == '3')
		return (1);
	else if (i - 1 >= 0 && data->parse.map[i - 1][j + 1] && \
	data->parse.map[i - 1][j + 1] == '3')
		return (1);
	return (0);
}

int	finding_closeness(t_data *data, int i, int j)
{
	int	save;

	save = last_linked(data, i, j);
	if (data->parse.map[i][j] == '1' && save == j)
	{
		if (finding_closeness1(data, i, j))
			return (1);
	}
	return (0);
}
