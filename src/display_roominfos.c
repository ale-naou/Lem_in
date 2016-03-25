/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_options2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:13:30 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/25 13:43:59 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	display_roominfos2(t_env *e)
{
	t_room	*room;

	room = e->room_start;
	while (room != NULL)
	{
		ft_putstr(room->name);
		ft_putchar('	');
		ft_putnbr(room->x);
		ft_putchar('	');
		ft_putnbr(room->y);
		ft_putchar('	');
		ft_putstr(room->start == 1 ? "  X" : " ");
		ft_putchar('	');
		ft_putstr(room->end == 1 ? " X" : " ");
		ft_putchar('	');
		ft_putstr("   ");
		ft_putnbr(room->n_links);
		ft_putchar('\n');
		room = room->next;
	}
}

void		display_roominfos(t_env *e)
{
	ft_putchar('\n');
	ft_putendl("	 -------------");
	ft_putendl("	| ROOMS INFOS |");
	ft_putendl("	 -------------");
	ft_putstr("Name");
	ft_putchar('	');
	ft_putstr("X");
	ft_putchar('	');
	ft_putstr("Y");
	ft_putchar('	');
	ft_putstr("start");
	ft_putchar('	');
	ft_putstr("end");
	ft_putchar('	');
	ft_putstr("n links");
	ft_putchar('\n');
	display_roominfos2(e);
}
