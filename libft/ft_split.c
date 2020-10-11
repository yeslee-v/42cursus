/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:51:06 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/11 21:48:49 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int	i;
	int cnt;

	if ((!*s && !c) || !*s)
		return (0);
	else if (!c)
		return (*s);
	else
	{
		i = 0;
		cnt = 0;
		while (*s)
		{
			if (*s == c)
				cnt++;
			*s++;
		}
	}
}
