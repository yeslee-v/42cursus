/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:43:42 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/08 19:32:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp = dest;
	const char	*sp = src;
	
	if ((!dest) && (!src))
		return (0);

	while (n)
	{
		*dp++ = *sp++;
		n--;
	}
	return (dest);
}
