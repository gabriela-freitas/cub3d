/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:21:40 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/07 19:27:43 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main()
{
	t_data data;

	parse_map(&data, "/nfs/homes/dmendonc/cub3d/maps/firstmap.cub");
}