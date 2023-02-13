/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/13 02:49:15 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(int fd, int i, t_data *data);
static int	first_line(char *line);
static void	check_prefix(char **line, t_data *data);
static int	create_rgb(char *rgb, t_data *data);

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
	data->parse.size_map = 0;
	aux = data->parse.map;
	while (*(aux++))
	{
		if (!is_empty_line(*(aux - 1)))
		{
			printf("%s", *(aux - 1));
			data->parse.size_map++;
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
		if (!is_empty_line(*(aux)))
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
		aux++;
	}
}

static void	check_prefix(char **line, t_data *data)
{
	static char *prefix_list[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(prefix_list[i], line[0], ft_strlen(prefix_list[i])))
		{
			if (i < 4)
			{
				data->fd[i] = open(line[1], O_RDONLY);
				if (data->fd[i] == -1)
					printf("file not found %s\n", line[0]);
				//exit_message("file not found", data);
			}
			else
			{
				data->fd[i] = create_rgb(line[1], data);
				printf("code %d\n", data->fd[i]);
				if (data->fd[i] == -1)
					exit_message("invalid rgb code", data);
			}
		}
	}
}

static int	create_rgb(char *rgb, t_data *data)
{
	long int	r;
	long int	g;
	long int	b;
	char		**split;

	split = ft_split(rgb, ',');
	if (split[3])
	{
		free_split(split);
		exit_message("invalid map format", data);
	}
	r = ft_atol(split[0]);
	g = ft_atol(split[1]);
	b = ft_atol(split[2]);
	free_split(split);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (0 << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}
