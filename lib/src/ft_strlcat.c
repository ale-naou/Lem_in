/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:30:31 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/04 22:09:36 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			return (i);
		i++;
	}
	return (size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	ret;

	i = 0;
	if (size <= (ft_strnlen(dst, size) + 1))
		return (ft_strnlen(dst, size) + ft_strlen(src));
	len_dst = ft_strlen(dst);
	ret = len_dst + ft_strlen(src);
	while (src[i] != '\0')
	{
		if (len_dst < size - 1)
		{
			dst[len_dst] = src[i];
			len_dst++;
		}
		i++;
	}
	dst[len_dst] = '\0';
	return (ret);
}
