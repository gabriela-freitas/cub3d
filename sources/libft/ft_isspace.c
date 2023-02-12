/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:55:23 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/11 18:50:29 by gafreita         ###   ########.fr       */
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
		;
	if (!(*str))
		return (1);
	else
		return (0);
}
