/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/07 16:49:44 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	first_line_map(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (line == NULL)
		return (0);
	while(line[++i])
	{
		if (line[i] == '0')
			return(0);
		else if (line[i] == '1')
			flag++;
		else if (!(line[i] == '1' || line[i] == 9 || line[i] == ' '))
			return(0);
	}
	return (1);
}

int	last_line_map(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (line == NULL)
		return (0);
	while(line[++i])
	{
		if (line[i] == '0')
			return(0);
		else if (line[i] == '1')
			flag++;
		else if (!(line[i] == '1' || line[i] == 9 || line[i] == ' '))
			return(0);
	}
	return (1);
}

int	middle_line_map(char *line)
{
	int	i;

	i = -1;
	if (line == NULL)
		return (0);
	while(line[++i])
	{
		if (!(line[i] == '1' || line[i] == 9 || line[i] == ' ' \
		|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || \
		line[i] == 'E'))
			return (0);
	}
	return (1);
}

int	check_map(t_data *data)
{
	char	*line;

	line = get_next_line(data->map_fd);
	while(!first_line_map(line))
	{
		free(line);
		line = get_next_line(data->map_fd);
	}
	line = get_next_line(data->map_fd);
	while(!last_line_map(line))
	{
		if (middle_line_map(line) == 0)
		{
			free(line);
			printf("not a legal middle line");
			return (0);
		}
		free(line);
		line = get_next_line(data->map_fd);
	}
	return(1);
}