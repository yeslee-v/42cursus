/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:22:14 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/07 20:37:13 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	if ((!dest) && (!src))
		return (0);
	while (len--)
	{
		dest[i] == src[i];
		if (dest[i++] == c)
			return (dest[i + 1]);
	}
	return (0);
}
