/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:41:41 by ratinhosujo       #+#    #+#             */
/*   Updated: 2023/03/08 17:47:34 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	compare(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (!(s1[i] == '\0' && s2[i] == '\0'))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	looping(char const *s1, char const *set, int starter)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[starter] == set[i])
		{
			i = 0;
			starter++;
		}
		else
			i++;
	}
	return (starter);
}

int	give_last_rev(char const *s1, char const *set, int last)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[last] == set[i])
		{
			i = 0;
			last --;
		}
		else
			i++;
	}
	return (last);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		first;
	int		last;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	first = looping(s1, set, 0);
	if (first == (int)ft_strlen((char *)s1))
	{
		ptr = malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	last = ft_strlen((char *)s1) - 1;
	last = give_last_rev(s1, set, last);
	ptr = ft_substr(s1, (unsigned int)first, (last - first + 1));
	free(s1);
	return (ptr);
}
