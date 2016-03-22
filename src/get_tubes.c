/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:33:50 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 23:27:02 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_tube(t_env *e)
{
	t_tube	*tmp;

	if (!(tmp = (t_tube *)malloc(sizeof(t_tube))))
		error(e, 4, "Erreur malloc");
	tmp->start = ft_strdup(e->tab[0]);
	tmp->end = ft_strdup(e->tab[1]);
	if (e->tube_start == NULL)
	{
		tmp->next = NULL;
		e->tube_start = tmp;
		e->tube_end = tmp;
	}
	else
	{
		tmp->next = NULL;
		e->tube_end->next = tmp;
		e->tube_end = e->tube_end->next;
	}
	free(e->tab);
	e->tab = NULL;
}

int			is_tube(t_env *e)
{
	e->tab = ft_strsplit(e->line, '-');
	if (!e->tab[0] || !e->tab[1] || e->tab[2])
		return (-1);
	if (ft_strisprint(e->tab[0]) == 0 || ft_strisprint(e->tab[1]) == 0)
		return (-1);
	return (0);
}

int			get_tubes(t_env *e)
{
	if (get_comments(e) == 0)
	{
		if (is_tube(e) == 0)
		{
			add_tube(e);
			if (check_tube(e) == -1)
			{
				del_invalidtube(e);
				e->n_read = 3;
				return (-1);
			}
			else
				e->n_tubes++;
		}
		else
			return (-1);
	}
	else if (get_comments(e) == -1)
		return (1);
	return (0);
}
