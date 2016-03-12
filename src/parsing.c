/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:57:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/12 18:18:18 by ale-naou         ###   ########.fr       */
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
		else if (e->n_read == 2)
			get_tubes(e);
		get_display(e);
	}
	//display_var(e);
}
