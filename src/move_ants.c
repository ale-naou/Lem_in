/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:14:51 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/21 19:16:40 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_valid(t_ants *ants)
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

int		move_ants(t_env *e)
{
	t_ants *ants;
	int		n;

	n = 0;
	ants = e->ants_start;
	while (ants != NULL)
	{
		ft_putstr("*");
		ft_putnbr(room_valid(ants));
//		ft_putnbr(e->antsinend);
		ft_putstr("* ");
		if (ants->room->end != 1 && (n = room_valid(ants)) != -1)
		{
			ants->room->ant = 0;
			ants->room = ants->room->t_roomlinks[n];
			ants->room->ant = 1;
			if (ants->room->end == 1)
			{
				e->antsinend++;
				ants->room->ant = 0;
			}
			ft_putchar('L');
			ft_putnbr(ants->ants);
			ft_putchar('-');
			ft_putstr(ants->room->name);
		}
		ft_putchar('	');
		sleep(1);
		ants = ants->next;
	}
	ft_putchar('\n');
	return (0);
}

int		manage_ants(t_env *e)
{
	while (e->antsinend < e->n_ants)
		move_ants(e);
	return (0);
}
