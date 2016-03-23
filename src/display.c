/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:40:09 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/23 19:15:42 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_antsmoves(t_ants *ants)
{
	ft_putchar('L');
	ft_putnbr(ants->ants);
	ft_putchar('-');
	ft_putstr(ants->room->name);
	ft_putchar(' ');
}

void		get_display(t_env *e)
{
	t_dis	*tmp;

	(!(tmp = (t_dis *)malloc(sizeof(t_dis)))) ?
		error(e, 4, "Erreur malloc") : 0;
	tmp->next = NULL;
	tmp->str = ft_strdup(e->line);
	if (e->dis_start == NULL)
	{
		e->dis_start = tmp;
		e->dis_end = tmp;
	}
	else
	{
		e->dis_end->next = tmp;
		e->dis_end = e->dis_end->next;
	}
	ft_strdel(&e->line);
}

void		display(t_env *e)
{
	t_dis	*tmp;

	tmp = e->dis_start;
	while (tmp != NULL)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
		ft_strdel(&e->dis_start->str);
		free(e->dis_start);
		e->dis_start = NULL;
		e->dis_start = tmp;
	}
	ft_putchar('\n');
}
