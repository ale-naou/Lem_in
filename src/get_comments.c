/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:41 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 16:34:34 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_comments(t_env *e)
{
	if (e->line[0] == '#')
	{
		if (e->line[1] != '#')
			return (1);
		if (ft_strcmp(e->line, "##start") != 0 &&
				ft_strcmp(e->line, "##end") != 0)
		{
			ft_putendl("Bad command input");
			return (-1);
		}
	}
	return (0);
}
