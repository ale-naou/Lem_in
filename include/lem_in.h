/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:07:22 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/07 19:53:46 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/include/libft.h"
# include <stdlib.h>

typedef struct 		s_env
{
	int				n_ants;
	int				n_rooms;
	int				n_tubes;
	char			*line;
}					t_env;

#endif
