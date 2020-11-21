/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:00:48 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/21 12:20:53 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...);

int	ft_len(int i)
{
	int	len;

	len = 1;
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	return (len);
}
