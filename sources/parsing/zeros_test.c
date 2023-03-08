/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeros_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:36:59 by dmendonc          #+#    #+#             */
/*   Updated: 2023/03/08 11:44:34 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

int	check_zeros(t_data *data, int i, int j, int sides)
{
	if (i - 1 >= 0 && data->map.map[i - 1][j] && (data->map.map[i - 1][j] == \
	'0' || data->map.map[i - 1][j] == '1' || data->map.map[i - 1][j] == 'N' || \
	data->map.map[i - 1][j] == 'S' || data->map.map[i - 1][j] == 'E' || \
	data->map.map[i - 1][j] == 'W'))
		sides++;
	if (i + 1 < data->map.map_height && data->map.map[i + 1][j] && \
	(data->map.map[i + 1][j] == '0' || data->map.map[i + 1][j] == '1' || \
	data->map.map[i + 1][j] == 'N' || data->map.map[i + 1][j] == 'S' || \
	data->map.map[i + 1][j] == 'E' || data->map.map[i + 1][j] == 'W'))
		sides++;
	if (j - 1 >= 0 && data->map.map[i][j - 1] && (data->map.map[i][j - 1] == \
	'0' || data->map.map[i][j - 1] == '1' || data->map.map[i][j - 1] == 'N' || \
	data->map.map[i][j - 1] == 'S' || data->map.map[i][j - 1] == 'E' || \
	data->map.map[i][j - 1] == 'W'))
		sides++;
	if (data->map.map[i][j + 1] && (data->map.map[i][j + 1] == \
	'0' || data->map.map[i][j + 1] == '1' || data->map.map[i][j + 1] == 'N' || \
	data->map.map[i][j + 1] == 'S' || data->map.map[i][j + 1] == 'E' || \
	data->map.map[i][j + 1] == 'W'))
		sides++;
	if (sides == 4)
		return (1);
	return (0);
}

int	zeros_testing(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == '0')
			{
				if (!check_zeros(data, i, j, 0))
					return (0);
			}
		}
	}
	return (1);
}
