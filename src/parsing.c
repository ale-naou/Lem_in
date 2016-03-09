/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:57:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/09 19:54:05 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_rooms_ends(t_env *e)
{
	t_room	*tmp;

	ft_strcmp(e->line, "##start") == 0 && e->start_mark == 0 ?
		e->start_mark = 1 : error(e, 5, "Multiples starts notifications");
	ft_strcmp(e->line, "##end") == 0 && e->end_mark == 0 ?
		e->end_mark = 1 : error(e, 5, "Multiples ends notifications");
	ft_get_next_line(e->fd, &e->line);
	if (e->line != NULL)
		(!(tmp = (t_room *)malloc(sizeof(t_room)))) ?
			error(e, 4, "Error malloc") : 0;
	else
		error(e, 3, "No rooms specify after ends specification");
	e->start_mark == 1 ? e->start = tmp : 0;
	e->end_mark == 1 ? e->end = tmp : 0;
	e->room_split = ft_strsplit(e->line, ' ');
	return (0);
}

int		get_rooms(t_env *e)
{
	t_room	*tmp;

	if ((ft_strcmp(e->line, "##start") == 0) || (ft_strcmp(e->line, "##end")) == 0)
		get_rooms_ends(e);
	else if (e->line != NULL)
		if (!(tmp = (t_room *)malloc(sizeof(t_room))))
			error(e, 4, "Error malloc");
	return (0);
}


static int		get_ants(t_env *e)
{
	e->n_ants = ft_atof(e->line);
	if (e->n_ants < MIN_INT || e->n_ants > MAX_INT)
		error(e, 2, "Either WAAAY too much ants or not enough at all");
	e->n_read++;
	return (e->n_ants);
}

void			parsing(t_env *e)
{
	t_room	*tmp;
	t_tube	*tmp2;

	(void)tmp;	
	(void)tmp2;
	while (ft_get_next_line(e->fd, &e->line) != 0)
	{
		e->n_read == 0 && get_ants(e) <= 0 ? error(e, 1, "No ants") : 0;
		e->n_read == 1 && get_rooms(e) != 0 ? error(e, 3, "Error rooms format") : 0;
		ft_putendl(e->line);
	}
	debug_message(e);
}
