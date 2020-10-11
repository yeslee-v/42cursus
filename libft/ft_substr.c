/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:03:24 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/11 16:49:36 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*c;
	unsigned int	i;
	unsigned int 	j;

	if (!*s)
		return (0);
	c = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = ft_strlen(s);
	if ((start + len) > j)
		return (0);
	else
	{
		while (i < start)
			i++;
		while (i < (start + len))
		{
			c[i] = (char)s[i];
			i++;
		}
	}
	return (c);
}
