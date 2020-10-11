/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:04:36 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/11 16:59:30 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!*s1 && !*s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	*s3 = malloc(sizeof(char) * (i + j + 1);
	while (*s1)
		*s3++ = (char *)s1++;
	while (*s2)
		*s3++ = (char *)s2++;
	s3[i + j + 1] = '\0';
	return (s3);
}
