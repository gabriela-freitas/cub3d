/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/08 21:08:00 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Returns the first line of the map :

int	first_line(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (line[++i] != '\n')
	{
		if (line[i] == '0')
			return (0);
		else if (line[i] == '1')
			flag++;
		else if (!(line[i] == '1' || line[i] == 9 || line[i] == ' '))
			return (0);
	}
	if (flag > 0)
		return (1);
}
