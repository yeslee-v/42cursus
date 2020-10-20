/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:05 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/20 18:57:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			cnt++;
		}
	}
	return (cnt);
}

static int		*ft_n_malloc(char **all, size_t k, size_t cnt)
{
	if (!(all[k] = malloc(cnt + 1)))
	{
		while (k > 0)
		{
			k--;
			free(all[k]);
		}
	}
	return (0);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	cnt;
	char	**all;

	if (!s)
		return (0);
	if (!(all = malloc(sizeof(char *) * (ft_cnt(s, c) + 1))))
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		cnt = 0;
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
		{
			i++;
			cnt++;
		}
		ft_n_malloc(all, k, cnt);
		l = 0;
		j = i - cnt;
		while (j < i)
		{
			all[k][l] = (char)s[j];
			j++;
			l++;
		}
		all[k][l] = '\0';
		k++;
	}
	all[k] = 0;
	return (all);
}
