/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:06:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/18 19:29:41 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		debug(t_env *e)
{
	ft_putstr("Coucou ");
	ft_putnbr(e->debug);
	ft_putchar('\n');
	e->debug++;
}

void		display_var(t_env *e)     //
{
	t_room	*room;
	t_tube	*tube;
	ft_putnbr(e->n_ants);
	ft_putchar('\n');

	room = e->room_start;
	tube = e->tube_start;
	while (room != NULL)
	{
		ft_putstr(room->name);
		ft_putchar('	');
		ft_putnbr(room->x);
		ft_putchar('	');
		ft_putnbr(room->y);
		ft_putstr("\e[31m");
		ft_putchar('	');
		ft_putstr("s : ");
		ft_putnbr(room->start);
		ft_putstr("\e[0m");		
		ft_putstr("\e[32m");
		ft_putchar('	');
		ft_putstr("end : ");
		ft_putnbr(room->end);
		ft_putstr("\e[0m");
		ft_putchar('	');
		ft_putnbr(room->n_links);
		ft_putchar('\n');
		room = room->next;
	}
	while (tube != NULL)
	{
		ft_putstr(tube->start);
		ft_putchar('-');
		ft_putstr(tube->end);
		ft_putchar('\n');
		tube = tube->next;
	}
}                                       //

void		display_roomlinks(t_env *e)
{
	t_room	*room;
	int		i;

	room = e->room_start;
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

static void	init_env(t_env *e)
{
	e->fd = 0;
	e->line = NULL;
	e->n_read = 0;
	e->n_ants = 0;
	e->n_rooms = 0;
	e->n_tubes = 0;
	e->r_tab = NULL;
	e->t_tab = NULL;
	e->dis_start = NULL;
	e->dis_end = NULL;
	e->room_start = NULL;
	e->room_end = NULL;
	e->tube_start = NULL;
	e->tube_end = NULL;
	e->start_mark = 0;
	e->end_mark = 0;
}

int			main(void)
{
	t_env	e;

	e.debug = 1;
	
	init_env(&e);
	parsing(&e);
	create_link(&e);
//	display(&e);
	display_var(&e);
	display_roomlinks(&e);
	return (0);
}
