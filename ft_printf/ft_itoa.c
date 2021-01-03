/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:49:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/03 21:42:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *c)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(c);
	str = malloc(sizeof(char) * (i + 1));
	j = 0;
	if (!str)
		return (0);
	while (c[j])
	{
		str[j] = c[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_input(size_t i, size_t len, int n, char *c)
{
	while (i < len)
	{
		c[len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*c;

	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	len += ft_len(n);
	i = 0;
	if (!(c = malloc(len + 1)))
		return (0);
	ft_input(i, len, n, c);
	if (len != ft_len(n))
		c[0] = '-';
	c[len] = '\0';
	return (c);
}
