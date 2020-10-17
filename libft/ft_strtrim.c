/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:58:33 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/17 14:19:23 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*s2;

	if (!*s1)
		return (0);
	size = ft_strlen(s1);
	if (!(s2 = malloc((size + 1))))
		return (0);
	s2 = (char *)s1;
	i = 0;
	while (s2[i])
	{
		j = 0;
		if (s2[i] == set[j])
		{
			s2[i] = '\0';
			i++;
		}
		else if (!set[j])
			break ;
		j++;
	}
	while (size < 0)
	{
		j = 0;
		if (s1[size] != set[j])
		{
			j++;
			if (!set[j])
				break ;
		}
		else
			size--;
	}
	s2[size + 1] = '\0';
	return (s2);
}
