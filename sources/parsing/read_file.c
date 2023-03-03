/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/03/03 16:51:19 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(int fd, int i, t_data *data);
static int	first_line(char *line);

/*Reads the file and puts its content in
	data->file
	and the first line of the map in
	data->map.map*/

void	read_file(char *file_name, t_data *data)
{
	int		fd;
	char	**aux;

	data->file = NULL;
	if (!ft_strrchr(file_name, '.')
		|| ft_strncmp(ft_strrchr(file_name, '.'), ".cub\0", 6))
		exit_message("Invalid file name", data);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_message("Map file not found", data);
	fill_map(fd, 0, data);
	data->map.map = data->file;
	while (*data->map.map && !first_line(*data->map.map))
		data->map.map++;
	if (!(*data->map.map) || data->map.map == data->file )
		exit_message("Invalid map file", data);
	aux = data->map.map;
	while (*(aux++))
	{
		if (!is_empty_line(*(aux - 1)))
			printf("%s", *(aux - 1));
	}
}

// Check if it's the first line of the map

static int	first_line(char *line)
{
	int	i;

	i = -1;
	if (is_empty_line(line))
		return (0);
	while (line[++i] != '\n' && line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'W'
				|| line[i] == 'S' || line[i] == 'N' || line[i] == 'E'
				|| ft_isspace(line[i])))
			return (0);
	}
	return (1);
}

/*Read from the file and fill the data->map.map (char **) recursively*/

static void	fill_map(int fd, int i, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		fill_map(fd, i + 1, data);
	else
	{
		(data)->file = malloc(sizeof(char *) * (i + 1));
		if (!(data)->file)
			exit_message("Malloc error", (data));
	}
	(data)->file[i] = line;
}
