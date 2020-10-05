/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:03:42 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/05 16:32:17 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*temp = b;

	i = 0;
	while (i < len)
	{
		*((char*) temp + i) = c;
		i++;
	}
	return (b);
}
