/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:51:06 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/12 22:29:27 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(const char *s, char c)
{
	int len;
	int flag;

	len = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			len++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (len);
}

static	char	*ft_dup(const char *s, int i, int j)
{
	char	*str;
	int		idx;

	i = 0;
	str = malloc(sizeof(char) * (j - i));
	while (i < j)
		str[idx++] = s[i++];
	str[idx] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		idx;
	char	**result;

	if (!s || !(result = malloc(((ft_size(s, c) + 1)))))
		return (0);
	i = 0;
	j = 0;
	idx = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && idx < 0)
			idx = i;
		else if ((s[i] == c || i == ft_strlen(s)) && idx >= 0)
		{
			result = ft_dup(s, idx, i);
			idx = -1;
		}
		i++;
	}
}
