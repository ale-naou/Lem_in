/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:21:00 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 19:39:36 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_room(t_env *e)
{
	t_room	*tmp;

	if (e->room_start == NULL)
	{
		(!(tmp = (t_room *)malloc(sizeof(t_room)))) ?
			error(e, 4, "Erreur malloc") : 0;
		tmp->name = e->room_split[0];
		tmp->x = ft_atof(e->room_split[1]);
		tmp->y = ft_atof(e->room_split[2]);
		tmp->next = NULL;
		e->room_start = tmp;
		e->room_end = tmp;
	}
	else
	{
		(!(tmp = (t_room *)malloc(sizeof(t_room)))) ?
			error(e, 4, "Erreur malloc") : 0;
		tmp->name = e->room_split[0];
		tmp->x = ft_atof(e->room_split[1]);
		tmp->y = ft_atof(e->room_split[2]);
		tmp->next = NULL;
		e->room_end->next = tmp;
		e->room_end = e->room_end->next ;
	}
}

static int		is_room(t_env *e)
{
	(void)e;
	return (0);
}

static void		get_rooms_ends(t_env *e)
{
	ft_strcmp(e->line, "##start") == 0 ? e->start_mark++ : 0;
	ft_strcmp(e->line, "##end") == 0 ? e->end_mark++ : 0;
	e->start_mark > 1 || e->end_mark > 1 ?
		error(e, 5, "Multiples starts or ends notifications") : 0;
}

void			get_rooms(t_env *e)
{

	if (get_comments(e) == 0)
	{
		if ((ft_strcmp(e->line, "##start") == 0) ||
				(ft_strcmp(e->line, "##end")) == 0)
			get_rooms_ends(e);
		if (is_room(e) == 0)
		{
			add_room(e);
			e->n_rooms++;
		}
	}
}
