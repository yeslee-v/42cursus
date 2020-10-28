/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:48:22 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/28 21:53:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);

int		get_next_line(int fd, char **line);
int		ft_strlen(char *s);

# endif
