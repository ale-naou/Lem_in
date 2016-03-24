/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:41 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 17:44:39 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_comment(t_env *e)
{
	t_com	*com;

	(!(com = (t_com *)malloc(sizeof(t_com)))) ?
		error(e, 4, "ERROR : malloc") : 0;
	com->str = NULL;
	com->str = ft_strdup(&e->line[1]);
	com->next = NULL;
	if (e->com_start == NULL)
	{
		e->com_start = com;
		e->com_end = com;
	}
	else
	{
		e->com_end->next = com;
		e->com_end = e->com_end->next;
	}
}

int				get_comments(t_env *e)
{
	static int	i;

	if (e->line[0] == '#')
	{
		if (e->line[1] != '#')
		{
			if (i == 1)
			{
				add_comment(e);
				i = 0;
			}
			else
				i = 1;
			return (1);
		}
		if (ft_strcmp(e->line, "##start") != 0 &&
				ft_strcmp(e->line, "##end") != 0)
			return (-1);
	}
	return (0);
}
