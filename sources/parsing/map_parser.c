/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:34:30 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Frees the allocated memory and exits the program*/
void	exit_message(char *message, t_data *data)
{
	free_split(data->parse.file);
	printf("%s\n", message);
	exit(0);
}
