/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:51:01 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/05 17:22:03 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen((char *)s2);
	if (len == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			while (s1[i + j] == s2[j])
			{
				j++;
				len--;
				if (len <= 0)
					return ((char *)&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
