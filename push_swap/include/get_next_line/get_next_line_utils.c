/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:48:06 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/06 15:18:52 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *c)
{
	int		i;
	int		j;
	char	*str;

	if (!c)
		return (0);
	i = ft_strlen_gnl(c);
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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s3;

	if (!(s3 = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)))
		return (0);
	i = -1;
	j = -1;
	k = 0;
	while (s1[++i])
	{
		s3[k] = s1[i];
		k++;
	}
	while (s2[++j])
	{
		s3[k] = s2[j];
		k++;
	}
	s3[k] = '\0';
	return (s3);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
