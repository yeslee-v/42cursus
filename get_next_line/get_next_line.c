/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:55 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/30 21:10:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*isremain; // check '\n', if don't initailize, fill 0 automatically
	char		buf[BUFFER_SIZE + 1];
	int			idx;
	int			reader; // read에서 얼마만큼 byte를 읽어왔는지

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (!(isremain = malloc(sizeof(char) + 1))) // malloc(1) is also correct!
		return (-1);
	if (!(line = malloc(sizeof(char *) + 1)))
		return (-1);
	while (!(ft_strchr(isremain, '\n')) && 
			((reader = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[reader] = '\0';
		isremain = ft_strjoin(isremain, buf);
	}
	idx = -1;
	while (isremain[++idx] != '\n')
		*line[idx] = isremain[idx];
	*line[idx] = '\0';
	isremain = ft_strdup(&isremain[idx + 1]);
}
/*
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
}*/
