/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:43:30 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 15:13:34 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_to_hex(char *str)
{
	int		i;
	int		e;
	int		hex;

	i = ft_strlen(str);
	e = 1;
	hex = 0;
	while (--i >= 0 && e <= 1048576)
	{
		if (ft_isdigit(str[i]))
			hex += (str[i] - '0') * e;
		else if (str[i] >= 'a' && str[i] <= 'f')
			hex += (str[i] - 'a' + 10) * e;
		else if (str[i] >= 'A' && str[i] <= 'F')
			hex += (str[i] - 'A' + 10) * e;
		e *= 16;
	}
	return (hex);
}
