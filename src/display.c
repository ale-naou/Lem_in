/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:40:09 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 17:36:30 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			display(t_env *e)
{
	while (e->dis_start != NULL)
	{
		ft_putendl(e->dis_start->str);
		e->dis_start = e->dis_start->next;
	}
	ft_putchar('\n');
}
