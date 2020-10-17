/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:49:00 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/16 19:38:24 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int n)
{
	int		cnt;

	cnt = 0;
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	int		i;
	int		mod;
	int		len;
	char	*c;

	i = 0;
	len = ft_size(n);
	if (n > 9)
	{
		c = malloc(sizeof(char) * (len + 1));
		if (!c)
			return (0);
		while (i++ < len)
		{
			mod = n % 10 + '0';
			c[i] = mod;
			n /= 10;
		}
	}
	else
	{
		n += '0';
		c = (char *)malloc(sizeof(char) * 2);
		c[0] = n;
		c[1] = '\0';
	}
	return (c);
}
