/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:19:12 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 16:25:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ants(t_env *e)
{
	if (get_comments(e) == 0)
	{
		e->n_ants = ft_atof(e->line);
		if (e->n_ants < MIN_INT || e->n_ants > MAX_INT)
			error(e, 1, "Either WAAAY too much ants or not enough at all");
		if (e->n_ants <= 0)
			error(e, 1, "No ants");
		e->n_read++;
	}
}
