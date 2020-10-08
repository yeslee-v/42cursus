/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:35:50 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/08 20:48:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strchr(char *str, int c)
{
	int i;

	if (str == '\0')
		return (0);
	else
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == c)
				return (*str);
			i++;
		}
	}
	return (0);
}
