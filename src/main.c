/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:06:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 19:03:28 by ale-naou         ###   ########.fr       */
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
	e->room_split = NULL;
	e->tube_split = NULL;
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
	display(&e);
	return (0);
}
