/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:33:15 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/08 21:52:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	else
	{
		while (big[i])
		{
			while ((big[i + j] == little[i]) && (i + j) < len)
			{
				if ((big[i + j] == '\0') && (little[j] == '\0'))
					return ((char *)big + i);
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
			j++;
		}
	}
	return (0);
}
