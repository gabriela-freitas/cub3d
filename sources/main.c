/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/07 21:57:00 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	t_data data;

	parse_map(&data, "/nfs/homes/dmendonc/cub3d/maps/firstmap.cub");
}
