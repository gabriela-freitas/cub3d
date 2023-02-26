/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:26:11 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/26 17:29:48 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_image(t_wall *wall, char **file, t_data *data);
static void	check_prefix(char **line, t_data *data);
static int	create_rgb(char *rgb, t_data *data);

void	get_file_info(t_data *data)
{
	char	**aux;
	char	**line;

	aux = data->file;
	while (aux != data->map.map)
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

static void	open_image(t_wall *wall, char **file, t_data *data)
{
	wall->img = mlx_xpm_file_to_image(data->mlx.p_mlx,
			file[0], &wall->width, &wall->height);
	free_split(file);
	if (!wall->img)
	{
		printf("texture not found %s\n", file[0]);
		exit_message("", data);
	}
	wall->addr = mlx_get_data_addr(wall->img, &wall->bits_per_pixel,
			&wall->line_length, &wall->endian);
}

static void	check_prefix(char **line, t_data *data)
{
	int			i;
	char		**aux;
	static char	*prefix_list[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	i = -1;
	while (++i < 6)
	{
		if (!ft_strncmp(prefix_list[i], line[0], ft_strlen(prefix_list[i])))
		{
			if (i < 4)
			{
				aux = ft_split(line[1], '\n');
				open_image(&data->wall[i], aux, data);
			}
			else
				data->colors[i - 4] = create_rgb(line[1], data);
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
		exit_message("invalid rgb code", data);
	return (0 << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}
