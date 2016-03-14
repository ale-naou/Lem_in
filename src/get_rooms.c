/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:21:00 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/14 19:45:46 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_room(t_env *e)
{
	t_room	*tmp;

	(!(tmp = (t_room *)malloc(sizeof(t_room)))) ?
		error(e, 4, "Erreur malloc") : 0;
	tmp->start = 0;
	tmp->end = 0;
	if (e->start_mark == 1) 
	{
		tmp->start = 1;
		e->start_mark += 10;
	}
	if (e->end_mark == 1) 
	{
		tmp->end = 1;
		e->end_mark += 10;
	}
	tmp->name = e->r_tab[0];
	tmp->x = ft_atof(e->r_tab[1]);
	tmp->y = ft_atof(e->r_tab[2]);	
	tmp->next = NULL;
	if (e->room_start == NULL)
	{
		e->room_start = tmp;
		e->room_end = tmp;
	}
	else
	{
		e->room_end->next = tmp;
		e->room_end = e->room_end->next ;
	}	

}

static int		is_room(t_env *e)
{
	e->r_tab = ft_strsplit(e->line, ' ');
	if (e->r_tab[0] && !e->r_tab[1])
	{
		if (is_tube(e) == 0)
		{
			add_tube(e);
			e->n_tubes++;
			e->n_read = 2;
			return (1);
		}
	}
	if (!e->r_tab[0] || !e->r_tab[1] || !e->r_tab[2])
		error(e, 7, "Invalid room 1");
	if (e->r_tab[3])
		error(e, 7, "Invalid room 1");
	if (ft_strisprint(e->r_tab[0]) == 0 || ft_strisdigit(e->r_tab[1]) == 0 ||
			ft_strisdigit(e->r_tab[2]) == 0)
		error(e, 7, "Invalid room 2");
	return (0);
}

void			get_rooms(t_env *e)
{

	if (get_comments(e) == 0)
	{
		if ((ft_strcmp(e->line, "##start") == 0) ||
				(ft_strcmp(e->line, "##end")) == 0)
		{
			ft_strcmp(e->line, "##start") == 0 ? e->start_mark++ : 0;
			ft_strcmp(e->line, "##end") == 0 ? e->end_mark++ : 0;
			if (e->start_mark > 1 && e->end_mark > 1)
				error(e, 5, "Multiples starts or ends notifications");
		}
		else if (is_room(e) == 0)
		{
			add_room(e);
			e->n_rooms++;
		}
	}
}
