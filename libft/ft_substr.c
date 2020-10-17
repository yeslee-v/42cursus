/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:03:24 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/16 21:48:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*c;
	unsigned int	i;
	unsigned int	j;

	if (!*s || !len)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(c = malloc(sizeof(char))))
			return (0);
		c[0] = '\0';
		return (c);
	}
	else
	{
		if (!(c = malloc(sizeof(char) * (len + 1))))
			return (0);
		i = 0;
		while (i < start)
			i++;
		j = 0;
		while (i < (start + len))
			c[j++] = (char)s[i++];
	}
	c[j] = '\0';
	return (c);
}
