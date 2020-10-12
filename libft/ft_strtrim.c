/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:58:33 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/12 22:21:51 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s2;
	
	if (!*s1 && !*set)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s2 = (char *)malloc(sizeof(char) * (i - j + 1));
	while (*s1)
	{
		if (*s1 != *set)
			*s2++ = *s1;
		s1++;
	}
	return (s2);
}
