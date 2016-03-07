/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:42:34 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/13 14:42:40 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while ((n /= 10) > 0)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	size_t			size;
	char			*str;
	unsigned int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n);
	if ((str = (char *)malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	str[size] = 0;
	size--;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (size != 0)
	{
		str[size--] = n % 10 + '0';
		n /= 10;
	}
	if (str[0] != '-')
		str[0] = (n % 10) + '0';
	return (str);
}
