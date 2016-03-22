/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:19:03 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 23:26:56 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_roomend(t_env *e)
{
	t_room *room;

	room = e->room_start;
	while (room != NULL)
	{
		if (room->end == 1)
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_room	*find_roomstart(t_env *e)
{
	t_room *room;

	room = e->room_start;
	while (room != NULL)
	{
		if (room->start == 1)
			return (room);
		room = room->next;
	}
	return (NULL);
}

int		create_antlist(t_env *e)
{
	t_ants	*ants;
	int		i;

	i = 0;
	while (++i <= e->n_ants)
	{
		if (!(ants = (t_ants *)malloc(sizeof(t_ants))))
			error(e, 4, "Error malloc");
		ants->ants = i;
		ants->move = 0;
		ants->room = find_roomstart(e);
		ants->next = NULL;
		if (e->ants_start == NULL)
		{
			e->ants_start = ants;
			e->ants_end = ants;
		}
		else
		{
			e->ants_end->next = ants;
			e->ants_end = ants;
		}
		ants = ants->next;
	}
	return (0);
}

void	recursive(t_env *e, t_room *path, int n)
{
	int		i;

	i = 0;
	n++;
	path->weight = n;
	while (i < path->n_links)
	{
		if (path->t_roomlinks[i]->start == 1)
		{
			e->mapvalid++;
			break ;
		}
		if (path->t_roomlinks[i] && path->t_roomlinks[i]->start == 0 &&
				path->t_roomlinks[i]->weight == MAX_INT)
			recursive(e, path->t_roomlinks[i], n);
		i++;	
	}
}

int		resolve(t_env *e)
{
	create_antlist(e);
	recursive(e, find_roomend(e), 0);
	if (e->mapvalid == 0)
	{
		ft_putendl("ERROR : No links between start and end");
		exit(0);
	}
	return (0);
}
