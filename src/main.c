/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:06:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/09 19:54:06 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void debug_message(t_env *e)     //
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
	e->r->name = NULL;
	e->r->x = 0;
	e->r->y = 0;
	e->n_read = 0;
	e->room_split = NULL;
	e->start_mark = 0;
	e->end_mark = 0;
}

int		main(void)
{
	t_env	e;

	init_env(&e);
	parsing(&e);
	return (0);
}
