/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:07:22 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/10 16:57:35 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/include/libft.h"
# include <stdlib.h>

#define MAX_INT 2147483647
#define MIN_INT	-2147483648

typedef struct		s_tube
{
	struct s_room	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	double			x;
	double			y;
	int				start;
	int				end;
	struct s_room	*next;
}					t_room;

typedef struct 		s_env
{
	t_tube			*t;
	t_room			*start;
	t_room			*end;
	char			**room_split;
	double			n_read;
	double			n_ants;
	double			n_rooms;
	int				start_mark;
	int				end_mark;
	double			n_tubes;
	int				fd;
	char			*line;
	int				debug;					//
}					t_env;


/*
**	Parsing
*/

void				parsing(t_env *e);

/*
**	Miscaellenous
*/

void				error(t_env *e, int n, char *str);

/*
**	Debug Fonctions
*/

void				display_var(t_env *e);	//
void				debug(t_env *e);		//

#endif
