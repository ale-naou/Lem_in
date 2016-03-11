/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:48:18 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 18:32:29 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_display(t_env *e)
{
	t_dis		*tmp;

	if (e->dis_start == NULL)
	{
		(!(tmp = (t_dis *)malloc(sizeof(t_dis)))) ?
			error(e, 4, "Erreur malloc"): 0;
		tmp->next = NULL;
		tmp->str = e->line;
		e->dis_start = tmp;
		e->dis_end = tmp;
	}
	else
	{
		(!(tmp = (t_dis *)malloc(sizeof(t_dis)))) ?
			error(e, 4, "Erreur malloc"): 0;
		tmp->next = NULL;
		tmp->str = e->line;
		e->dis_end->next = tmp;
		e->dis_end = e->dis_end->next;
	}
}
