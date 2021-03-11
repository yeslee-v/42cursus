/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/11 22:07:16 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_double_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_read_line(char *line, t_all *all)
{
	int		len;
	char	**res;

	if (all->game.cnt == 8)
		ft_read_map(line, all);
	else
		if (ft_isspace(line[0]))
			ft_error_message(6);
	res = ft_split(line, ' ');
	len = ft_double_strlen(res);
	if (ft_strnstr(res[0], "R", ft_strlen(res[0])) && len == 3)
		ft_put_size(res[1], res[2], &(all->game));
	else if (ft_strnstr(res[0], "NO", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], &(all->game));
	else if (ft_strnstr(res[0], "SO", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], &(all->game));
	else if (ft_strnstr(res[0], "WE", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], &(all->game));
	else if (ft_strnstr(res[0], "EA", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], &(all->game));
	else if (ft_strnstr(res[0], "S", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], &(all->game));
	else if (ft_strnstr(res[0], "F", ft_strlen(res[0])) && len == 2)
		ft_put_color(res[1], all->game.f, &(all->game));
	else if (ft_strnstr(res[0], "C", ft_strlen(res[0])) && len == 2)
		ft_put_color(res[1], all->game.c, &(all->game));
}
