/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:33:50 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/14 13:38:21 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_tube(t_env *e)
{
	t_tube	*tmp;

	if (e->tube_start == NULL)
	{
		(!(tmp = (t_tube *)malloc(sizeof(t_tube))))	?
			error(e, 4, "Erreur malloc") : 0;
		tmp->start = e->t_tab[0];
		tmp->end = e->t_tab[1];
		tmp->next = NULL;
		e->tube_start = tmp;
		e->tube_end = tmp;
	}
	else
	{
		(!(tmp = (t_tube *)malloc(sizeof(t_tube))))	?
			error(e, 4, "Erreur malloc") : 0;
		tmp->start = e->t_tab[0];
		tmp->end = e->t_tab[1];
		tmp->next = NULL;
		e->tube_end->next = tmp;
		e->tube_end = e->tube_end->next;
	}
}

int		is_tube(t_env *e)
{
	e->t_tab = ft_strsplit(e->line, '-');
	if (!e->t_tab[0] || !e->t_tab[1])
		error(e, 8, "Invalid tube 1");
	if (ft_strisprint(e->t_tab[0]) == 0 || ft_strisprint(e->t_tab[1]) == 0)
		error(e, 8, "Invalid tube 2");
	return (0);
}

void			get_tubes(t_env *e)
{
	if (get_comments(e) == 0)
	{
		if (is_tube(e) == 0)
		{
			add_tube(e);
			e->n_tubes++;
		}
	}
}
