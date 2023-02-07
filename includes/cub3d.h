/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/07 19:57:14 by dmendonc         ###   ########.fr       */
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

typedef struct s_data
{
	int	map_fd;

} t_data;

// MAP CHECKING

int		check_map(t_data *data);
int		last_line_map(char *line); // testa se e a ultima linha -> tem que so ter espacos, tabs, ou 1's
int		first_line_map(char *line); // testa se e a primeira linha -> tem que so ter espacos, tabs, ou 1's
int		middle_line_map(char *line); // testa se e a primeira linha -> tem que so ter espacos, tabs, ou 1's
void	parse_map(t_data *data, char *file_name);

#endif
