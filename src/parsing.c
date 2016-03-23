/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:57:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/23 17:50:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			parsing(t_env *e)
{
	while (ft_get_next_line(e->fd, &e->line) != 0)
	{
		if (e->n_read == 0)
		{
			if (get_ants(e) == 0)
				get_display(e);
			else if (get_ants(e) == -1)
				error(e, 11, "ERROR : Ants");
		}
		else if (e->n_read == 1)
		{
			if (get_rooms(e) != -1)
				get_display(e);
		}
		if (e->n_read == 2)
		{
			if (get_tubes(e) == 0)
				get_display(e);
			else if (get_tubes(e) == -1)
				break ;
		}
		ft_strdel(&e->line);
	}
}
