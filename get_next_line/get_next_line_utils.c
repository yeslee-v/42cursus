/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:48:06 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/26 21:43:14 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *c)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(c);
	str = malloc(sizeof(char) * (i + 1));
	j = 0;
	if (!str)
		return (0);
	while (c[j])
	{
		str[j] = c[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
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
