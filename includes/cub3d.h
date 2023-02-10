/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/09 23:49:28 by ratinhosujo      ###   ########.fr       */
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

typedef struct s_difus
{
	int	i;
	int	j;
	int	flag;
	int	ret;
	int	max_i;
	int	difusion;
	int	size_map;
} t_difus;

typedef struct s_parsing
{
	char	**file;
	char	**map;
}	t_parse;


typedef struct s_data
{
	t_difus difus;
	t_parse parse;
	char *NO;

} t_data;

// MAP CHECKING

int		compare(const char *s1, const char *s2);
int		first_line(char *line);
void	exit_message(char *message);

void	create_test_map(t_data *data);

// burning method
int		burn_map(t_data *data);
int		rev_burn_map(t_data *data);
int		burn_first_row(t_data *data);
int		burn_last_row(t_data *data);
int 	adjacent_burned(t_data *data, int i, int j);
int 	adjacent_burned2(t_data *data, int i, int j);
int		linked_line(t_data *data, int index);


// map checker
int		check_char(t_data *data);
int		one_position(t_data *data);
int		closed_map(t_data *data);
int		map_test(t_data *data);
void	print_map(t_data *data);

#endif
