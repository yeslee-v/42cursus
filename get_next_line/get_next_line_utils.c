/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:48:06 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/25 21:08:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s3;

	if (!s1)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	k = 0;
	while (*s1)
		s3[k++] = *(s1++);
	while (*s2)
		s3[k++] = *(s2++);
	s3[k] = '\0';
	return (s3);
}
