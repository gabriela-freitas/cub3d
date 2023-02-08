/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:00:16 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
	#define CUB3D

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../get_next_line/get_next_line.h"

#define TRUE 1
#define FALSE 0

typedef struct s_parsing
{
	char	**file;
	char	**map;
}	t_parse;


typedef struct s_data
{
	t_parse parse;
	char *NO;

} t_data;

// MAP CHECKING

char	*get_first_line(t_data *data);
char	*get_last_line(t_data *data);
int		middle_line_map(char *line);
int		map_test(t_data *data);
void	parse_map(t_data *data);

#endif
