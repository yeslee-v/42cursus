/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:05:53 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/07 21:14:12 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p = (unsigned char*)s;

	while (n--)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
	}
	return (0);
}
