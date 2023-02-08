/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:27:51 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/08 21:08:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	exit_message(char *message)
{
	//FREE MAP
	printf("%s\n", message);
	exit(0);
}

/*Check if its a valid file name and a valid map
And saves the map*/

