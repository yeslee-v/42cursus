/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:21:05 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/13 17:26:36 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cnt_comma(char *line)
{
	int i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (line[++i])
	{
		if (line[i] == ',')
			cnt++;
	}
	return (cnt);
}

int		ft_check_atoi(char *s)
{
	int		i;
	int		ret;
	char	*trim_s;

	i = 0;
	trim_s = ft_strtrim(s, " ");
	while (trim_s[i])
	{
		if (!(ft_isdigit(trim_s[i])))
			ft_error_message(4);
		i++;
	}
	ret = ft_atoi(trim_s);
	free(trim_s);
	return (ret);
}
