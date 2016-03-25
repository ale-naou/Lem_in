/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:40:09 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/25 11:55:33 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_color g_color[12] = {
	{0, C_RED},
	{1, C_GREEN},
	{2, C_YELLOW},
	{3, C_BLUE},
	{4, C_MAG},
	{5, C_CYAN},
	{6, C_LRED},
	{7, C_LGREEN},
	{8, C_LYELLOW},
	{9, C_LBLUE},
	{10, C_LMAG},
	{11, C_LCYAN}};

void		color_ants(int ants)
{
	int i;
	int index;

	i = 0;
	index = ants % 11;
	if (ants != 0 && ants != 46)
	{
		while (g_color[i].index != index)
			i++;
		ft_putstr(g_color[i].color);
	}
}

void		print_antsmoves(int opt, t_ants *ants)
{
	option('c', opt) ? color_ants(ants->ants) : 0;
	ft_putchar('L');
	ft_putnbr(ants->ants);
	ft_putchar('-');
	ft_putstr(ants->room->name);
	ft_putchar(' ');
	option('c', opt) ? ft_putstr(C_END) : 0;
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
