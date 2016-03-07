/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:18:11 by ale-naou          #+#    #+#             */
/*   Updated: 2015/12/05 17:06:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(len));
	len--;
	while (s[len] == '\n' || s[len] == ' ' || s[len] == '\t')
	{
		if (len == 0)
			return (ft_strnew(len));
		len--;
	}
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
		i++;
	len = len - i + 1;
	str = ft_strsub(s, i, len);
	return (str);
}
