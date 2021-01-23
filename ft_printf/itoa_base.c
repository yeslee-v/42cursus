/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:22:07 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 23:13:20 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_max_value(char type)
{
	if (type == 'u')
		return ("4294967295");
	else if (type == 'X')
		return ("FFFFFFFF");
	else if (type == 'x')
		return ("ffffffff");
	else
		return ("-1");
}

int		ft_len_base(long long num, int base, int i)
{
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_itoa_base(long long value, int base, char type)
{
	int			i;
	int			sign;
	long long	num;
	char		*str;

	num = (value < 0) ? -value : value;
	sign = (value < 0 && base == 10) ? 1 : 0;
	i = (sign) ? 1 : 0;
	if (value == 4294967295)
		return (ft_max_value(type));
	i = ft_len_base(num, base, i);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = (value == 0) ? '0' : '\0';
	while (i-- + sign)
	{
		if (num % base < 10)
			str[i] = (num % base + '0');
		else
			str[i] = ((type == 'x') || (type == 'p')) ? (num % base + 'a' - 10)
										: (num % base + 'A' - 10);
		num /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
