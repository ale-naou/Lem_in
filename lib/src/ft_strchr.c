/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:18:07 by ale-naou          #+#    #+#             */
/*   Updated: 2016/01/04 12:44:23 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)s;
	while (ret[i] != '\0')
	{
		if (ret[i] == c)
			return (&ret[i]);
		i++;
	}
	if (ret[i] == c)
		return (&ret[i]);
	else
		return (NULL);
}
