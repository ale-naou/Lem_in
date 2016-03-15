/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:36:18 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/15 18:44:39 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_tube_connec(t_env *e, t_tube *tube)
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

int		check_tube(t_env *e)
{
	t_tube	*tube;

	tube = e->tube_start;
	while (tube != NULL)
	{
		if (ft_strcmp(tube->start, tube->end) != 0)
		{
			if (check_tube_connec(e, tube) == 0)
				tube = tube->next;
			else
			{
				ft_putendl("Tube connected to a room that doesn't exist");
				return (-1);
			}
		}
		else
		{
			ft_putendl("Tube conecting a room with itself");
			return (-1);
		}
	}
	return (0);
}
