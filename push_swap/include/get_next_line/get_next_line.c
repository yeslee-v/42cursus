/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:55 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/06 15:19:56 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_current_line(char **line, char **isremain, char *tmp)
{
	char	*save;

	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup_gnl(*isremain);
		save = ft_strdup_gnl(tmp + 1);
		free(*isremain);
		*isremain = save;
		return (1);
	}
	*line = ft_strdup_gnl(*isremain);
	free(*isremain);
	*isremain = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*isremain;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!isremain)
		isremain = ft_strdup_gnl("");
	while (!(tmp = ft_strchr_gnl(isremain, '\n')) &&
			((reader = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[reader] = '\0';
		tmp = ft_strjoin_gnl(isremain, buf);
		free(isremain);
		isremain = tmp;
	}
	if (reader < 0)
		return (-1);
	return (get_current_line(line, &isremain, tmp));
}
