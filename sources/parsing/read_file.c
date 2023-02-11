/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/11 21:21:07 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(int fd, int i, t_data *data);
static int	first_line(char *line);

/*Reads the file and puts its content in
	data->parse.file
	and the first line of the map in
	data->parse.map*/
void	read_file(char *file_name, t_data *data)
{
	int		fd;
	char	**aux;

	data->parse.file = NULL;
	if (!ft_strrchr(file_name, '.')
		|| ft_strncmp(ft_strrchr(file_name, '.'), ".cub\0", 6))
		exit_message("Invalid file name", data);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_message("Map file not found", data);
	fill_map(fd, 0, data);
	data->parse.map = data->parse.file;
	while (!first_line(*data->parse.map))
		data->parse.map++;
	data->parse.height = 0;
	aux = data->parse.map;
	while (*(aux++))
	{
		if (!is_empty_line(*(aux - 1)))
		{
			printf("%s", *(aux - 1));
			data->parse.height++;
		}
	}
}

// Check if it's the first line of the map
static int	first_line(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (line[++i] != '\n' && line[i])
	{
		if (line[i] == '0')
			return (0);
		else if (line[i] == '1')
			flag++;
		else if (!(line[i] == '1' || line[i] == 9 || line[i] == ' '))
			return (0);
	}
	if (flag > 0)
		return (1);
	else
		return (0);
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
		(data)->parse.file = malloc(sizeof(char *) * (i + 1));
		if (!(data)->parse.file)
			exit_message("Malloc error", (data));
	}
	(data)->parse.file[i] = line;
}

void	get_file_info(t_data *data)
{
	char	**aux;
	char	**line;

	aux = data->parse.file;
	while (aux != data->parse.map)
	{
		if (!is_empty_line(*(aux++)))
		{
			line = ft_split(*aux, ' ');
			if (!line[2])
				check_prefix(line, data);
			else
			{
				free_split(line);
				exit_message("wrong file format", data);
			}
			free_split(line);
		}
	}
}

static int	check_prefix(char **line, t_data *data)
{
	static char *prefix_list[5] = {"NO", "SO", "WE", "EA", "F", "C"};
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (!ft_strncmp(prefix_list[i], line[0], ft_strlen(prefix_list[i])))
		{
			if (i < 4)
			{
				data->fd[i] = open(line[1], O_RDONLY);
				if (data->fd[i] == -1)
					exit_message("Map file not found", data);
			}
			// else
			// 	//add to rgbd
		}
	}
}

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }
