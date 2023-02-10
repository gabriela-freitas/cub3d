/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_linked.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:49:42 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/02/10 18:04:55 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	last2_linked(t_data *data, int i)
{
	int	jay;

	jay = -1;
	while (data->parse.map[i][++jay])
	{
		if (data->parse.map[i][jay] == '2')
		{
			if (data->parse.map[i][jay + 1] && \
			data->parse.map[i][jay + 1] == '2')
				continue ;
			else
				break ;
		}
	}
	return (jay);
}

int	last_linked(t_data *data, int i, int j)
{
	int	jay;
	int	save;

	(void)j;
	jay = last2_linked(data, i);
	save = jay;
	while (data->parse.map[i][jay])
		jay++;
	while (data->parse.map[i][--jay])
	{
		if (adjacent_burned(data, i, jay) && data->parse.map[i][jay] == '1')
		{
			save = jay;
			break ;
		}
	}
	return (save);
}
