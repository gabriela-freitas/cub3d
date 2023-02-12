/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:28:17 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/11 21:18:32 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "../get_next_line/get_next_line.h"

# define TRUE 1
# define FALSE 0

enum e_keys{
	key_W = 119,
	key_S = 115,
	key_A = 97,
	key_D = 100,
	key_ESC = 65307
};

enum e_prefix{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

typedef struct s_difus
{
	int	i;
	int	j;
	int	flag;
	int	ret;
	int	max_i;
	int	first_one;
	int	last_one;
	int	starting;
	int	size_map;
}	t_difus;

typedef struct s_parsing
{
	char	**file;
	char	**map;
	int		size_map;
}	t_parse;

typedef struct s_data
{
	t_parse	parse;
	int		fd[6];
	t_difus	difus;
}	t_data;

// MAP CHECKING

int		compare(const char *s1, const char *s2);
void	create_test_map(t_data *data);

// burning method
int		burn_map(t_data *data);
int		burn_burned(t_data *data);
int		rev_burn_map(t_data *data);
int		burn_first_row(t_data *data);
int		last_linked(t_data *data, int i, int j);
int		adjacent_burned(t_data *data, int i, int j);
int		adjacent_burned2(t_data *data, int i, int j);
int		finding_closeness(t_data *data, int i, int j);

// map checker
int		check_char(t_data *data);
int		one_position(t_data *data);
int		closed_map(t_data *data);
int		map_test(t_data *data);

void	exit_message(char *message, t_data *data);
void	read_file(char *file_name, t_data *data); //gabi
void	get_file_info(t_data *data);
void	print_map(t_data *data);

#endif
