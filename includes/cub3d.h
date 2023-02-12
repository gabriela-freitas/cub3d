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

typedef struct s_parsing
{
	char	**file;
	char	**map;
	int		height;
}	t_parse;

typedef struct s_data
{
	t_parse	parse;
	int		fd[6];
}	t_data;

// MAP CHECKING

char	*get_first_line(t_data *data);
char	*get_last_line(t_data *data);
int		middle_line_map(char *line);
int		map_test(t_data *data);

void	exit_message(char *message, t_data *data);
void	read_file(char *file_name, t_data *data); //gabi
void	get_file_info(t_data *data);

#endif
