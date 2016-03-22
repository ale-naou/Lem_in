/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:25:33 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 18:23:00 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(t_env *e, char *str)
{
	t_room	*tmp;

	tmp = e->room_start;
	while (tmp != NULL)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			add_linkedrooms(t_env *e, t_room *r, t_tube *t)
{
	if (ft_strcmp(r->name, t->start) == 0)
	{
		r->t_roomlinks[e->i] = find_room(e, t->end);
		return (1);
	}
	else if (ft_strcmp(r->name, t->end) == 0)
	{
		r->t_roomlinks[e->i] = find_room(e, t->start);
		return (1);
	}
	return (0);
}

void		linking_rooms(t_env *e, t_room *room)
{
	t_tube	*tube;
	t_tube	*tmp_tube;

	e->i = -1;
	tmp_tube = e->tube_start;
	while (++e->i < room->n_links)
	{
		tube = tmp_tube;
		while (tube != NULL)
		{
			if (add_linkedrooms(e, room, tube) != 0)
			{
				tube = tube->next;
				tmp_tube = tube;
				break ;
			}
			tube = tube->next;
		}
	}
}

int			define_nlinks(t_env *e, t_room *room)
{
	t_tube	*tube;
	int		i;

	i = 0;
	tube = e->tube_start;
	while (tube != NULL)
	{
		if (ft_strcmp(room->name, tube->start) == 0 ||
				ft_strcmp(room->name, tube->end) == 0)
			i++;
		tube = tube->next;
	}
	return (i);
}

int			create_link(t_env *e)
{
	t_room	*room;

	room = e->room_start;
	while (room != NULL)
	{
		room->n_links = define_nlinks(e, room);
		if (!(room->t_roomlinks =
					(t_room**)malloc(sizeof(t_room *) * (room->n_links + 1))))
			error(e, 4, "Error malloc");
		linking_rooms(e, room);
		room->t_roomlinks[e->i] = NULL;
		room = room->next;
	}
	return (0);
}
