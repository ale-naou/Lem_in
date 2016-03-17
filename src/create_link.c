/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:25:33 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/17 19:09:00 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		linking_rooms(t_env *e, t_room *room)
{
	int		i;
	t_tube	*tube;
	t_tube	*tmp_tube;

	tube = tube_start;
	while (i < room->n_links)
	{
		tube = tmp_tube;
		while (tube != NULL)
		{
			if (ft_strcmp(room->name, tube->start) == 0)
			{
				room->t_roomlinks[i] = tube->end;
				tmp_tube = tube;
				break ;
			}
			else if (ft_strcmp(room->name, tube->end) == 0)
			{
				room->t_roomlinks[i] = tube->start;
				tmp_tube = tube;
				break ;
			}
			tube = tube->next;
		}
		i++;
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
			(t_room**)malloc(sizeof(t_room *) * room->n_links)))
			error(e, 4, "Error malloc");
		linking_rooms(e, room);
		room = room->next;
	}
	return (0);
}
