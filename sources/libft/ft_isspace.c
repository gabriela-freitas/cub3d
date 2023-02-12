/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:sources/libft/ft_isspace.c
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:55:23 by gafreita          #+#    #+#             */
/*   Updated: 2023/02/11 18:50:29 by gafreita         ###   ########.fr       */
=======
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:27 by dmendonc          #+#    #+#             */
/*   Updated: 2023/02/09 14:31:54 by ratinhosujo      ###   ########.fr       */
>>>>>>> master:sources/parsing/first_line.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
<<<<<<< HEAD:sources/libft/ft_isspace.c
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
=======
	return (0);
>>>>>>> master:sources/parsing/first_line.c
}
