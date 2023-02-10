/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:00:28 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/10 00:52:42 by ratinhosujo      ###   ########.fr       */
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
	printf("%d\n", i);
	while (data->parse.map[++i])
	{
		j = -1;
		while (data->parse.map[i][++j])
		{
			printf("%d\n", data->parse.map[i][j]);
			if (data->parse.map[i][j] == 'N' || data->parse.map[i][j] == 'S' \
			|| data->parse.map[i][j] == 'E' || data->parse.map[i][j] == 'W')
			{
				printf("entrou");
				flag++;
			}
		}
	}
	if (flag == 1)
		return (1);
	else
		return (0);
}

int	closed_map(t_data *data)
{
	data->difus.flag = 1;
	if (!burn_first_row(data))		// burns first row
		return (0);
	// if (!linked_line(data, 0))		// checks if first line linked
	// 	return (0);
	print_map(data);
	while(data->difus.flag > 0)		// burns linked spots
	{
		if (!burn_map(data))
		{
			printf("\nBurn top to bottom has stoped.\n");
			break ;
		}
		print_map(data);
	}
	if (!burn_last_row(data))		// burns first row
		return (0);
	print_map(data);
	data->difus.flag = 1;
	while(data->difus.flag > 0)		// burns linked spots
	{
		if (!rev_burn_map(data))
			printf("Burn bottom to top has stoped.\n");
		print_map(data);
	}
	/* if (!linked_line(data, 0))		// checks if first line linked
	{
		printf("\n❌ top not linked.\n");
		return (0);
	}
	else
		printf("\n✅ top is linked.\n");
	if (!linked_line(data, data->difus.size_map - 1)) // checks if last line linked
	{
		printf("\n❌ bot not linked\n");
		return (0);
	}
	else
		printf("✅ bot is linked.\n"); */
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
		return (0);
	return(1);
}
