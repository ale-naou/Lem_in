/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:40:36 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/07 12:47:47 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen((char *)s2);
	if (len == 0)
		return ((char *)s1);
	while ((s1[i] != '\0' && i <= n) && n != 0)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j])
			{
				j++;
				len--;
				if (len == 0 && (i + j) <= n)
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
