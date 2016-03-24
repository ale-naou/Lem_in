/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:40:09 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/24 20:01:09 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*color_ants()
{
	static int	i = 0;
	char		*str;

	i == 0 ? str = C_RED : 0;
	i == 1 ? str = C_GREEN : 0;
	i == 2 ? str = C_YELLOW : 0;
	i == 3 ? str = C_BLUE : 0;
	i == 4 ? str = C_MAG : 0;
	i == 5 ? str = C_CYAN : 0;
	i == 6 ? str = C_LRED : 0;
	i == 7 ? str = C_LGREEN : 0;
	i == 8 ? str = C_LYELLOW : 0;
	i == 9 ? str = C_LBLUE : 0;
	i == 10 ? str = C_LMAG : 0;
	i == 11 ? str = C_LCYAN : 0;
	if (i < 11)
		i++;
	else
		i = 0;
	return (str);
}

void		print_antsmoves(int opt, t_ants *ants)
{

	option('c', opt) ? ft_putstr(color_ants()) : 0;
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
