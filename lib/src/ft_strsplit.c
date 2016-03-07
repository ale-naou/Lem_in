/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:31:41 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 14:42:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	size_t	wc;

	while (*s && *s == c)
		s++;
	wc = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			wc++;
		s++;
	}
	return (wc);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	wc;
	char	*start;
	char	**tab;

	wc = ft_wcount((char*)s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	start = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(tab++) = ft_strsub(start, 0, s - start);
			start = (char*)s + 1;
		}
		s++;
	}
	if (start != s)
		*(tab++) = ft_strsub(start, 0, s - start);
	*tab = NULL;
	return (tab - wc);
}
