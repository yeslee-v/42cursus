/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:37:05 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/19 22:26:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	char	**all;
	char	*floor;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		cnt = 0;
		if (s[cnt] != c)
			cnt++;
		else
		{
			if (!(floor = malloc(cnt + 1)))
				return (0);
			while (i < cnt)
			{
				floor[i] = s[i];
				i++;
			}
			floor[i] = '\0';
		}
	}
	return (all);
}
