/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:14:51 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 20:01:13 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_end(t_room *room)
{
	int		i;

	i = 0;
	while (room->t_roomlinks[i] != NULL)
	{
		if (room->t_roomlinks[i]->end == 1)
			return (1);
		i++;
	}
	return (0);
}

int				room_valid(t_ants *ants)
{
	int		i;
	int		res;
	int		weight;

	i = -1;
	res = -1;
	weight = MAX_INT;
	while (++i < ants->room->n_links)
	{
		if (ants->room->end == 1)
			return (i);
		if (ants->room->t_roomlinks[i]->ant == 0)
		{
			if (ants->room->t_roomlinks[i]->weight < weight)
			{
				if (ants->room->t_roomlinks[i]->start != 1)
				{
					weight = ants->room->t_roomlinks[i]->weight;
					res = i;
				}
			}
		}
	}
	return (res);
}

static t_ants	*move_ants2(t_env *e, t_ants *ants, int n)
{
	ants->room->ant = 0;
	ants->room = ants->room->t_roomlinks[n];
	ants->room->ant = 1;
	if (ants->room->end == 1)
	{
		e->antsinend++;
		ants->room->ant = 0;
	}
	return (ants);
}

void			move_ants(t_env *e)
{
	t_ants	*ants;
	int		n;

	n = 0;
	ants = e->ants_start;
	while (ants != NULL)
	{
		if (ants->room->start == 1 && find_end(ants->room) == 1)
		{
			ants = move_ants2(e, ants, n);
			print_antsmoves(e->opt, ants);
			break ;
		}
		if (ants->room->end != 1 && (n = room_valid(ants)) != -1)
		{
			ants = move_ants2(e, ants, n);
			print_antsmoves(e->opt, ants);
		}
		ants = ants->next;
	}
	ft_putchar('\n');
}

int				manage_ants(t_env *e)
{
	while (e->antsinend < e->n_ants)
		move_ants(e);
	return (0);
}
