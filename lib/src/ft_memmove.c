/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:07:45 by ale-naou          #+#    #+#             */
/*   Updated: 2015/11/30 14:36:25 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dst;
	char	*str_src;

	str_dst = (char *)dst;
	str_src = (char *)src;
	if (str_dst < str_src)
		ft_memcpy(dst, src, len);
	else
	{
		str_dst = str_dst + len;
		str_src = str_src + len;
		while (len)
		{
			*--str_dst = *--str_src;
			len--;
		}
	}
	return (dst);
}
