/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:01:03 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/23 20:13:04 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(t_env *e, int n, char *str)
{
	t_dis	*tmp;

	(void)n;
	if (e->dis_start != NULL)
	{
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
	}
	ft_putchar('\n');
	ft_putendl(str);
	display_var(e);
	exit(0);
}
