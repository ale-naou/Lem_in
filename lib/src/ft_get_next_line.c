/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:03:39 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/15 17:58:53 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ret_line(char **line, char **tmp, int fd, char *el)
{
	char		*del;

	if (!el)
	{
		*line = ft_strdup(tmp[fd]);
		ft_strdel(&tmp[fd]);
	}
	else
	{
		del = tmp[fd];
		*line = ft_strsub(tmp[fd], 0, el - tmp[fd]);
		tmp[fd] = ft_strsub(tmp[fd], el - tmp[fd] + 1,
				ft_strlen(el));
		ft_strdel(&del);
	}
}

int			ft_get_next_line(int const fd, char **line)
{
	static char	*tmp[256];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*del;
	char		*el;

	if (fd < 0 || BUFF_SIZE < 1 || fd > 256 || !line)
		return (-1);
	if (!(tmp[fd] = tmp[fd] == NULL ? ft_strnew(1) : tmp[fd]))
		return (-1);
	while (!(el = ft_strchr(tmp[fd], '\n')) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		del = tmp[fd];
		buf[ret] = '\0';
		if (!(tmp[fd] = ft_strjoin(tmp[fd], buf)))
			return (-1);
		ft_strdel(&del);
	}
	if (ret == -1)
		return (-1);
	ret_line(line, tmp, fd, el);
	return (!tmp[fd] && ft_strlen(*line) == 0 ? 0 : 1);
}
