/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 11:46:10 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 14:40:10 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		add_option(int pos, int opt)
{
	int		tmp;

	if (pos == -1)
	{
		ft_putendl("Wrong option called");
		exit(0);
	}
	tmp = 1;
	tmp = tmp << pos;
	opt = opt | tmp;
	return (opt);
}

static int		pos_option(char c)
{
	int		pos;

	pos = -1;
	while (OPTIONS[++pos])
	{
		if (c == OPTIONS[pos])
			return (pos);
	}
	return (-1);
}

int				option(char c, int opt)
{
	int		tmp;
	int		i;

	tmp = 1;
	i = pos_option(c);
	tmp = tmp << i;
	if (tmp & opt)
		return (1);
	return (0);
}

int				get_option(char **av)
{
	int		opt;
	int		i;
	int		j;

	i = -1;
	opt = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			while (av[i][++j])
				opt = add_option(pos_option(av[i][j]), opt);
		}
	}
	return (opt);
}
