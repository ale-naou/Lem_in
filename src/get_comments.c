/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:03:41 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/11 16:33:17 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_comments(t_env *e)
{
	if (e->line[0] == '#')
	{
		if (e->line[1] != '#')
			return (1);
		if (ft_strcmp(e->line, "##start") != 0 && ft_strcmp(e->line, "##end") != 0)
			error(e, 2, "Bad command input");
	}
	return (0);
}
