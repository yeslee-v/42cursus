/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:26:35 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/01 17:30:08 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_current_line(char **line, char **isremain, char *tmp)
{
	char	*save;

	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*isremain);
		save = ft_strdup(tmp + 1);
		free(*isremain);
		*isremain = save;
		return (1);
	}
	*line = ft_strdup(*isremain);
	free(*isremain);
	*isremain = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*isremains[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!isremains[fd])
		isremains[fd] = 0;
	while (!(tmp = ft_strchr(isremains[fd], '\n')) &&
			((reader = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[reader] = '\0';
		tmp = ft_strjoin(isremains[fd], buf);
		free(isremains[fd]);
		isremains[fd] = tmp;
	}
	if (reader < 0)
		return (-1);
	return (get_current_line(line, &isremains[fd], tmp));
}
