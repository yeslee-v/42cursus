/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:22:07 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/28 22:00:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_base(unsigned long long num, int base, int i)
{
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long long value, int base, char type)
{
	int			i;
	unsigned long long	num;
	char		*str;

	num = value;
	i = 0;
	i = ft_len_base(num, base, i);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (!(value))
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str[i] = '\0';
	while (i)
	{
		if (num % base < 10)
			str[--i] = (num % base + '0');
		else
			str[--i] = ((type == 'x') || (type == 'p')) ? (num % base + 'a' - 10)
										: (num % base + 'A' - 10);
		num /= base;
	}
	return (str);
}
