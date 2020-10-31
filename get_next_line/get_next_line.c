/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:55 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/31 17:30:09 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	get_current_line(char **line, char **isremain)
{
	int			idx;
	int			j;
	char		*tmp;

	idx = 0;
	while ((*isremain)[idx] != '\n' && (*isremain)[idx])
		idx++;
	if (!(tmp = (char *)malloc(idx + 1)))
		return ;
	j = 0;
	while (j < idx)
	{
		tmp[j] = (*isremain)[j];
		j++;
	}
	tmp[j] = '\0';
	//printf("* %c", isremain[idx + 1]);
	*line = tmp;
	if ((*isremain)[idx] == '\n')
	{
		tmp = ft_strdup(*isremain + (idx + 1));
		free(*isremain);
		*isremain = tmp;
		printf("hello: %s\n", *isremain);
		return ;
	}
	else
		*isremain = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char	*isremain;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(isremain = (char *)malloc(1)))
		return (-1);
	printf("Debugging: %s\n", isremain);
	while (!(ft_strchr(isremain, '\n')) && 
			((reader = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[reader] = '\0';
		tmp = ft_strjoin(isremain, buf);
		free(isremain);
		isremain = tmp;
	}
	if (reader < 0)
		return (-1);
	else if (!reader)
		return (0);
	get_current_line(line, &isremain);
	if (!isremain)
		return (0);
	return (1);
}
