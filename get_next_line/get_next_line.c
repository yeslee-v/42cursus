/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:47:55 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/29 21:14:55 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*isremain; // check '\n'
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!(tmp = malloc(sizeof(char) + 1)))
		return (-1);
	while (read(fd, buf, BUFFER_SIZE) != -1)
	{
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	while (*tmp != '\n')
		**line++ = tmp++;
	isremain = ft_strdup(tmp + 1);
	
}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("your_file_name", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
