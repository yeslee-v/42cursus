/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:55 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/30 22:45:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_current_line(char *isremain)
{
	int			idx;
	int			j;
	char		*tmp;

	idx = 0;
	while (isremain[idx] != '\n' && isremain[idx])
		idx++;
//	if (!isremain[idx])
//	{
//		free(isremain);
//		return (0);
//	}
	if (!(tmp = (char *)malloc(idx + 1)))
		return (NULL);
	j = 0;
	while (j < idx)
	{
		tmp[j] = isremain[j];
		j++;
	}
	tmp[j] = '\0';
//	if (!isremain[idx])
//		isremain = ft_strdup(&isremain[idx + 1]);
//	else
//		isremain = NULL;
	return (tmp);
}

char	*get_isremain(char *isremain)
{
	int		idx;
	int		j;
	char	*tmp;

	idx = 0;
	while (isremain[idx] != '\n' && isremain[idx])
		idx++;
	if (!isremain[idx])
	{
		free(isremain);
		return (0);
	}
	idx++;
	if (!(tmp = (char *)malloc(ft_strlen(isremain) - idx + 1)))
		return (NULL);
	j = 0;
	while (isremain[idx])
		tmp[j++] = isremain[idx++];
	tmp[j] = '\0';
	free(isremain);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*isremain;
	char		buf[BUFFER_SIZE + 1];
	int			reader;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	while (!(ft_strchr(isremain, '\n')) && 
			((reader = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		if (reader < 0)
			return (-1);
		buf[reader] = '\0';
		isremain = ft_strjoin(isremain, buf);
	}
	*line = get_current_line(isremain);
	isremain = get_isremain(isremain);
	if (!isremain)
		return (0);
	return (1);
}

int main(void)
{
	char *line = 0;
	int result;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
