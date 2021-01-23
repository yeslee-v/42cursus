/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:22:07 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 12:23:11 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_islist(char type)
{
	char	*hex;

	if (!(type))
		return ("0123456789ABCDEF");
	else
		hex = ((type == 'x') || (type == 'p'))
			? "0123456789abcdef" : "0123456789ABCDEF";
	return (hex);
}

char	*ft_max_value(char type)
{
	char	*s;

	if (type == 'u')
		s = "4294967295";
	else if (type == 'X')
		s = "FFFFFFFF";
	else if (type == 'x')
		s = "ffffffff";
	else
		s = "-1";
	return (s);
}

char	*ft_itoa_base(long long value, int base, char type)
{
	int		i;
	int		n;
	char	*s;
	char	*hex;

	n = value;
	hex = ft_islist(type);
	if (value == 4294967295)
		return (ft_max_value(type));
	i = (value < 0 && base == 10) ? 2 : 1;
	while (value /= base)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	s[i] = 0;
	if (n < 0 && base == 10)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}
