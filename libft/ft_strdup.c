/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:04:21 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/08 20:10:32 by yeslee           ###   ########.fr       */
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
	while (src[j++])
		str[j] = src[j];
	str[j] = "\0";
	return (str);
}
