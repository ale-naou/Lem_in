/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:06:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 19:06:51 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_env(t_env *e)
{
	e->fd = 0;
	e->opt = 0;
	e->line = NULL;
	e->n_read = 0;
	e->n_ants = 0;
	e->antsinend = 0;
	e->n_rooms = 0;
	e->n_tubes = 0;
	e->mapvalid = 0;
	e->tab = NULL;
	e->ants_start = NULL;
	e->ants_end = NULL;
	e->dis_start = NULL;
	e->dis_end = NULL;
	e->room_start = NULL;
	e->room_end = NULL;
	e->com_start = NULL;
	e->com_end = NULL;
	e->tube_start = NULL;
	e->tube_end = NULL;
	e->start_mark = 0;
	e->end_mark = 0;
}

void		aff_help(void)
{
	ft_putchar('	');
	ft_putendl("Usage	:	./lem_in < [file.map] [-Ccrlw]");
	ft_putchar('	');
	ft_putendl("[-c]	:	Add color on ants");
	ft_putchar('	');
	ft_putendl("[-r]	:	Display room infos");
	ft_putchar('	');
	ft_putendl("[-l]	:	Display links of each rooms");
	ft_putchar('	');
	ft_putendl("[-w]	:	Display weight of each rooms");
	ft_putchar('	');
	ft_putendl("[-C]	:	Display comments");
	exit(0);
}

int			main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	if (ac > 1)
		e.opt = get_option(&av[1]);
	option('h', e.opt) == 1 ? aff_help() : 0;
	parsing(&e);
	display(&e);
	if (check_room(&e) != -1)
	{
		create_link(&e);
		resolve(&e);
		manage_ants(&e);
	}
	display_options(&e);
	del_all(&e);
	return (0);
}
