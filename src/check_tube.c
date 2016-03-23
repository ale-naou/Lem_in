/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:36:18 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/23 20:06:51 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		del_invalidtube(t_env *e)
{
	t_tube	*tube;

	if (e->tube_start && e->tube_start->next)
	{
		tube = e->tube_start;
		while (tube->next != e->tube_end)
			tube = tube->next;
		ft_strdel(&e->tube_end->start);
		ft_strdel(&e->tube_end->end);
		free(e->tube_end);
		e->tube_end = NULL;
		tube->next = NULL;
		e->tube_end = tube;
	}
	else if (e->tube_start && !e->tube_start->next)
	{
		ft_strdel(&e->tube_start->start);
		ft_strdel(&e->tube_start->end);
		free(e->tube_start);
		e->tube_start = NULL;
	}
}

static int	check_tube_clone(t_env *e, t_tube *tube)
{
	t_tube	*t_verif;
	int		clone;
	int		rev_clone;

	(void)e;
	clone = 0;
	rev_clone = 0;
	t_verif = tube->next;
	while (t_verif != NULL)
	{
		(ft_strcmp(tube->start, t_verif->start) == 0 &&
			ft_strcmp(tube->end, t_verif->end) == 0) ? clone++ : 0;
		(ft_strcmp(tube->end, t_verif->start) == 0 &&
			ft_strcmp(tube->start, t_verif->end) == 0) ? rev_clone++ : 0;
		t_verif = t_verif->next;
	}
	if (clone != 0 || rev_clone != 0)
		return (-1);
	return (0);
}

static int	check_tube_connec(t_env *e, t_tube *tube)
{
	t_room	*room;
	int		start;
	int		end;

	start = 0;
	end = 0;
	room = e->room_start;
	while (room != NULL)
	{
		ft_strcmp(tube->start, room->name) == 0 ? start++ : 0;
		ft_strcmp(tube->end, room->name) == 0 ? end++ : 0;
		room = room->next;
	}
	if (start == 0 || end == 0)
		return (-1);
	return (0);
}

int			check_tube(t_env *e)
{
	t_tube	*tube;

	tube = e->tube_start;
	while (tube != NULL)
	{
		if (ft_strcmp(tube->start, tube->end) != 0)
		{
			if (check_tube_connec(e, tube) == 0)
			{
				if (check_tube_clone(e, tube) == 0)
					tube = tube->next;
				else
					return (-1);
			}
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}
