/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:59:14 by ale-naou          #+#    #+#             */
/*   Updated: 2015/11/30 16:05:57 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str_s1;
	char	*str_s2;
	size_t	i;

	str_s1 = (char *)s1;
	str_s2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str_s1[i] != str_s2[i])
			return ((unsigned char)str_s1[i] - (unsigned char)str_s2[i]);
		i++;
	}
	return (0);
}
