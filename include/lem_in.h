/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:07:22 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/21 19:16:47 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/include/libft.h"
# include <stdlib.h>

#define MAX_INT 2147483647
#define MIN_INT	-2147483648

typedef struct		s_dis
{
	char			*str;
	struct s_dis	*next;
}					t_dis;

typedef struct		s_tube
{
	char			*start;
	char			*end;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	int				weight;
	int				ant;
	int				n_links;
	struct s_room	**t_roomlinks;
	struct s_room	*next;
}					t_room;

typedef	struct		s_ants
{
	int				ants;
	int				move;
	t_room			*room;
	struct s_ants	*next;
}					t_ants;

typedef struct 		s_env
{
	t_room			*room_start;
	t_room			*room_end;
	int				start_mark;
	int				end_mark;
	t_tube			*tube_start;
	t_tube			*tube_end;
	t_ants			*ants_start;
	t_ants			*ants_end;
	t_dis			*dis_start;
	t_dis			*dis_end;
	char			**tab;
	int				mapvalid;
	double			n_read;
	double			n_ants;
	int				antsinend;
	double			n_rooms;
	double			n_tubes;
	int				i;
	int				fd;
	char			*line;

	int				debug;					//
}					t_env;


/*
**	Parsing and check
*/

void				parsing(t_env *e);
int					get_ants(t_env *e);
int					get_rooms(t_env *e);
int					get_tubes(t_env *e);
int					check_tube(t_env *e);
int					is_tube(t_env *e);
void				add_tube(t_env *e);
int					get_comments(t_env *e);
void				get_display(t_env *e);

/*
**	Linking rooms between them + pathfinding + algo fonctions
*/

int					create_link(t_env *e);
t_room				*find_roomstart(t_env *e);
t_room				*find_roomend(t_env *e);
int					resolve(t_env *e);
void				recursive(t_env *e, t_room *path, int n);
int					manage_ants(t_env *e);
int					move_ants(t_env *e);
int					room_valid(t_ants *ants);

/*
**	Deleting fonctions
*/

void				del_invalidtube(t_env *e);

/*
**	Miscaellenous
*/

void				display(t_env *e);
void				error(t_env *e, int n, char *str);

/*
**	Debug Fonctions
*/

void				display_var(t_env *e);	//
void				debug(t_env *e);		//

#endif
