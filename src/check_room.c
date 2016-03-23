/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:55:58 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/23 17:12:28 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ends(t_env *e)
{
	int		start;
	int		end;
	t_room	*room;

	start = 0;
	end = 0;
	room = e->room_start;
	while (room != NULL)
	{
		room->start == 1 ? start++ : 0;
		room->end == 1 ? end++ : 0;
		room = room->next;
	}
	if (start != 1 || end != 1)
		return (-1);
	return (0);
}

int		check_room(t_env *e)
{
	if (e->n_rooms <= 0)
		return (-1);
	if (check_ends(e) != 0)
		return (-1);
	return (0);
}
