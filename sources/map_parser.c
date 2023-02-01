/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/01 19:28:09 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*Check if its a valid file name and a valid map
And saves the map*/
void	parse_map(char *file_name)
{
	int		fd;
	int		i;

	if (!ft_strrchr(file_name, '.')
		|| ft_strncmp(ft_strrchr(file_name, '.'), ".ber\0", 6))
		exit_message("Invalid file name");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_message("Map file not found");
	init_variables();
	fill_map(fd, 0);
	i = -1;
	while (++i <= infos()->height)
		check_map(infos()->map[i], i, -1);
}

/*Read from the file and fill the map (char **) recursively*/
static void	fill_map(int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		fill_map(fd, i + 1);
	else
	{
		infos()->height = i;
		infos()->map = malloc(sizeof(char *) * (i + 1));
		if (!infos()->map)
			exit_message("Malloc error");
	}
	infos()->map[i] = line;
}
