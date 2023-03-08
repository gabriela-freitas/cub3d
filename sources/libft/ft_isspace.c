/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:55:23 by gafreita          #+#    #+#             */
/*   Updated: 2023/03/08 17:56:04 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	is_empty_line(char *str)
{
	if (!str || !(*str))
		return (1);
	while (*(str++) && ft_isspace(*(str - 1)))
	{
		if ((*str) == '\0')
		{
			return (1);
		}
	}
	return (0);
}
