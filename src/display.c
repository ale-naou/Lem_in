/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:40:09 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/21 16:54:26 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		display_ants(t_env *e)
{
	(void)e;
}

static void		display_list(t_env *e)
{
	while (e->dis_start != NULL)
	{
		ft_putendl(e->dis_start->str);
		e->dis_start = e->dis_start->next;
	}
}

void			display(t_env *e)
{
	display_list(e);
	ft_putchar('\n');
	display_ants(e);
}
