/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:05:55 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/25 13:44:02 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		display_comment(t_env *e)
{
	t_com	*com;
	int		i;

	i = 1;
	com = e->com_start;
	ft_putchar('\n');
	ft_putendl("	 ----------");
	ft_putendl("	| COMMENTS |");
	ft_putendl("	 ----------");
	while (com != NULL)
	{
		ft_putnbr(i);
		ft_putstr(".	");
		ft_putendl(com->str);
		com = com->next;
		i++;
	}
}

static void		display_roomweight(t_env *e)
{
	t_room	*room;

	room = e->room_start;
	ft_putchar('\n');
	ft_putendl("	 --------------");
	ft_putendl("	| ROOMS WEIGHT |");
	ft_putendl("	 --------------");
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
	ft_putchar('\n');
	ft_putendl("	 -------------");
	ft_putendl("	| ROOMS LINKS |");
	ft_putendl("	 -------------");
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

void			display_options(t_env *e)
{
	option('r', e->opt) == 1 ? display_roominfos(e) : 0;
	option('l', e->opt) == 1 ? display_roomlinks(e) : 0;
	option('w', e->opt) == 1 ? display_roomweight(e) : 0;
	option('C', e->opt) == 1 ? display_comment(e) : 0;
}
