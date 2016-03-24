/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:05:55 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 18:34:16 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		display_roominfos(t_env *e)
{
	t_room	*room;

	room = e->room_start;
	ft_putnbr(e->n_ants);
	ft_putchar('\n');
	while (room != NULL)
	{
		ft_putstr(room->name);
		ft_putchar('	');
		ft_putnbr(room->x);
		ft_putchar('	');
		ft_putnbr(room->y);
		ft_putstr(C_RED);
		ft_putchar('	');
		ft_putstr("s : ");
		ft_putnbr(room->start);
		ft_putstr(C_END);
		ft_putstr(C_GREEN);
		ft_putchar('	');
		ft_putstr("end : ");
		ft_putnbr(room->end);
		ft_putstr(C_END);
		ft_putchar('	');
		ft_putnbr(room->n_links);
		ft_putchar('\n');
		room = room->next;
	}
}

static void		display_comment(t_env *e)
{
	while (e->com_start != NULL)
	{
		ft_putstr("COMMENT MUDAFUCKA ==> ");
		ft_putendl(e->com_start->str);
		e->com_start = e->com_start->next;
	}
}

static void		display_roomweight(t_env *e)
{
	t_room	*room;

	room = e->room_start;
	ft_putendl("------------\nRooms Weight\n------------");
	while (room != NULL)
	{
		ft_putstr(room->name);
		ft_putchar('	');
		ft_putnbr(room->weight);
		ft_putchar('\n');
		room = room->next;
	}
}

static void		display_roomlinks(t_env *e)
{
	t_room	*room;
	int		i;

	room = e->room_start;
	ft_putendl("-----------\nRooms Links\n-----------");
	while (room != NULL)
	{
		ft_putendl(room->name);
		i = -1;
		while (++i < room->n_links)
		{
			ft_putchar('	');
			ft_putendl(room->t_roomlinks[i]->name);
		}
		room = room->next;
	}
}

void		display_options(t_env *e)
{
	option('r', e->opt) == 1 ? display_roominfos(e) : 0;
	option('l', e->opt) == 1 ? display_roomlinks(e) : 0;
	option('w', e->opt) == 1 ? display_roomweight(e) : 0;
	option('C', e->opt) == 1 ? display_comment(e) : 0;
}
