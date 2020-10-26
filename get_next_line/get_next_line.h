/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:48:22 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/26 21:43:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#IFNDEF GET_NEXT_LINE.H
# DEFINE GET_NEXT_LINE.H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd, char **line);
char	*ft_strdup(char *c);
char	*ft_strjoin(char *s1, char *s2);

# ENDIF
