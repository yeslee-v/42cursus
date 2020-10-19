/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:05 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/19 23:43:03 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 1;
	while (*s)
	{
		if (*s == c)
			cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	cnt;
	char	**all;
	char	*floor;

	if (!s)
		return (0);
	if (!(*all = malloc(sizeof(char *) * (ft_cnt(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		cnt = 0;
		if ((char)s[i] != c)
		{
			cnt++;
			i++;
		}
		else
		{
			if (!(floor = malloc(cnt + 1)))
				return (0);
			while (i < cnt)
			{
				floor[i] = s[i + cnt];
				i++;
			}
			floor[i] = '\0';
			all[j] = floor;
		}
		i++;
		j++;
	}
	*all[j] = '\0';
	return (all);
}
