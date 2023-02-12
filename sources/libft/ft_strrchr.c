/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:08:06 by gafreita          #+#    #+#             */
/*   Updated: 2022/03/03 21:09:18 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	hold;

	hold = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			hold = i;
		i ++;
	}
	if (hold >= 0)
		return ((char *)&s[hold]);
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
