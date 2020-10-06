/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:33:15 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/05 15:56:16 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	if (*little == "\0")
		return (0);
	else
	{
		i = 0;
		j = 0;
		while (big[j])
		{
			if (big[j] == little[i])
			{
				i++;
				if (little[i] == "\0")
					return (*little)
				}
			j++;
		}
	}
	return (0);
}
