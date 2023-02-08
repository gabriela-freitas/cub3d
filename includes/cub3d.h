/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:36:20 by gafreita         ###   ########.fr       */
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
#include "libft.h"

#include "../get_next_line/get_next_line.h"

#define TRUE 1
#define FALSE 0

typedef struct s_parsing
{
	char	**file;
	char	**map;
	int		height;
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

void	exit_message(char *message, t_data *data);
void	read_file(char *file_name, t_data *data); //gabi

#endif
