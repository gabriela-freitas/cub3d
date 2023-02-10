/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/10 18:23:20 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(int fd, int i, t_data *data);

// static int	first_line(char *line);
// // Check if it's the first line of the map
// static int	first_line(char *line)
// {
// 	int	i;
// 	int	flag;

// 	i = -1;
// 	flag = 0;

// 	while (line[++i] != '\n' && line[i])
// 	{
// 		if (line[i] == '0')
// 			return (0);
// 		else if (line[i] == '1')
// 			flag++;
// 		else if (!(line[i] == '1' || line[i] == 9 || line[i] == ' '))
// 			return (0);
// 	}
// 	if (flag > 0)
// 		return (1);
// 	else
// 		return (0);
// }

/*Reads the file and puts its content in
	data->parse.file
	and the first line of the map in
	data->parse.map*/
void	read_file(char *file_name, t_data *data)
{
	int		fd;

	data->parse.file = NULL;
	if (!ft_strrchr(file_name, '.')
		|| ft_strncmp(ft_strrchr(file_name, '.'), ".cub\0", 6))
		exit_message("Invalid file name", data);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_message("Map file not found", data);
	fill_map(fd, 0, data);
	printf("%s", data->parse.file[0]);
	// data->parse.map = data->parse.file;
	// printf("%d", first_line(*data->parse.file));
	// int i;
	// i = -1;
	// while (data->parse.file[++i])
	// {
	// 	printf("%s", data->parse.file[++i]);
	// }
	// while (!first_line(*data->parse.file))
	// {
	// 	printf("hey\n");
	// 	data->parse.file++;
	// }
}

/*Read from the file and fill the data->parse.map (char **) recursively*/
static void	fill_map(int fd, int i, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		fill_map(fd, i + 1, data);
	else
	{
		(data)->parse.height = i;
		(data)->parse.map = malloc(sizeof(char *) * (i + 1));
		if (!(data)->parse.map)
			exit_message("Malloc error", (data));
	}
	(data)->parse.map[i] = line;
}
