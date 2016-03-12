/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:06:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/12 18:56:02 by ale-naou         ###   ########.fr       */
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
	ft_putstr("\e[31m");
	ft_putstr("e->n_ants    : ");
	ft_putnbr(e->n_ants);
	ft_putchar('\n');
	ft_putstr("e->n_read    : ");
	ft_putnbr(e->n_read);
	ft_putchar('\n');
	ft_putstr("\e[0m");
}                                       //

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
//	display(&e);
	ft_putnbr(e.n_ants);
	ft_putchar('\n');
	while (e.room_start != NULL)
	{
		ft_putstr(e.room_start->name);
		ft_putchar('	');
		ft_putnbr(e.room_start->x);
		ft_putchar('	');
		ft_putnbr(e.room_start->y);
		ft_putstr("\e[31m");
		ft_putchar('	');
		ft_putstr("s : ");
		ft_putnbr(e.room_start->start);
		ft_putstr("\e[0m");		
		ft_putstr("\e[32m");
		ft_putchar('	');
		ft_putstr("end : ");
		ft_putnbr(e.room_start->end);
		ft_putstr("\e[0m");
		ft_putchar('\n');
		e.room_start = e.room_start->next;
	}
	while (e.tube_start != NULL)
	{
		ft_putstr(e.tube_start->start);
		ft_putchar('-');
		ft_putstr(e.tube_start->end);
		ft_putchar('\n');
		e.tube_start = e.tube_start->next;
	}
	return (0);
}
