/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:18:59 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/04 22:13:32 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	unsigned char	ccmp;
	unsigned int	i;

	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	ccmp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == ccmp)
			return (&str_dst[i] + 1);
		i++;
	}
	return (NULL);
}
