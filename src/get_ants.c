/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:19:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/22 17:34:25 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ants(t_env *e)
{
	if (get_comments(e) == 0)
	{
		if (ft_strisdigit(e->line) != 0)
		{
			e->n_ants = ft_atof(e->line);
			if (e->n_ants < MIN_INT || e->n_ants > MAX_INT)
			{
				ft_putendl("Either WAAAY too much ants or not enough at all");
				return (-1);
			}
			if (e->n_ants <= 0)
			{
				ft_putendl("No ants");
				return (-1);
			}
		}
		else
		{
			ft_putendl("Bad format for ants");
			return (-1);
		}
		e->n_read++;
	}
	else if (get_comments(e) == -1)
		return (1);
	return (0);
}
