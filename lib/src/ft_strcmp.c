/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:45 by ale-naou          #+#    #+#             */
/*   Updated: 2015/11/30 16:07:48 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		cmp;

	cmp = 0;
	while (s1[cmp] == s2[cmp] && s1[cmp] != '\0')
	{
		cmp++;
	}
	return ((unsigned char)s1[cmp] - (unsigned char)s2[cmp]);
}
