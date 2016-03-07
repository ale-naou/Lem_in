/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:22:47 by ale-naou          #+#    #+#             */
/*   Updated: 2015/11/30 17:11:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp;

	cmp = 0;
	if (n == 0)
		return (0);
	while ((cmp < n - 1) && (s1[cmp] == s2[cmp]) && (s1[cmp] != '\0'))
		cmp++;
	return ((unsigned char)s1[cmp] - (unsigned char)s2[cmp]);
}
