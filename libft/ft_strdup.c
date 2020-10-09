/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:04:21 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/09 15:57:13 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *c)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(c);
	str = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (c[j])
	{
		str[j] = c[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
