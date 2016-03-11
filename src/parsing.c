/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:57:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 18:32:37 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			parsing(t_env *e)
{
	while (ft_get_next_line(e->fd, &e->line) != 0)
	{
		if (e->n_read == 0)
			get_ants(e);
		else if (e->n_read == 1)
			get_rooms(e);
		get_display(e);
	}
	while (e->dis_start != NULL)
	{
		ft_putendl(e->dis_start->str);
		e->dis_start = e->dis_start->next;
	}
	//display_var(e);
}
