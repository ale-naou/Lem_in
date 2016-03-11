/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:33:50 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 19:40:56 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_tube(t_env *e)
{
	t_tube	*tmp;

	if (e->tube_start == NULL)
	{
		(!(tmp = (t_tube *)malloc(sizeof(t_tube))))	?
			error(e, 4, "Erreur malloc") : 0;
		tmp->start = e->tube_split[0];
		tmp->end = e->tube_split[1];
		tmp->next = NULL;
		e->tube_start = tmp;
		e->tube_end = tmp;
	}
	else
	{
		(!(tmp = (t_tube *)malloc(sizeof(t_tube))))	?
			error(e, 4, "Erreur malloc") : 0;
		tmp->start = e->tube_split[0];
		tmp->end = e->tube_split[1];
		tmp->next = NULL;
		e->tube_end->next = tmp;
		e->tube_end = e->tube_end->next;
	}

}

static int		is_tube(t_env *e)
{
	(void)e;
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
