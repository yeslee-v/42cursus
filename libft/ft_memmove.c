/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:40:27 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/07 21:05:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		temp;
	const unsigned char	*s;

	if (dest <= src)
	{
		temp = dest;
		s = src;
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		temp = dest;
		temp += n;
		s = src;
		s += n;
		while (n--)
			*--temp = *--src;
	}
	return (dest);
}
