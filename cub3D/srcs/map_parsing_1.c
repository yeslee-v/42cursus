/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/08 21:16:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int		len_id;
	char	**res;

	if (all->game.cnt == 8)
		ft_read_map(line, all);
	else if (ft_isspace(line[0]))
		ft_error_message(5);
	res = ft_split(line, ' ');
	len = ft_double_strlen(res);
	len_id = ft_strlen(res[0]);
	if (ft_strnstr(res[0], "R", len_id) && (len_id == 1) && (len == 3))
		ft_put_size(res[1], res[2], &(all->game));
	else if (ft_strnstr(res[0], "NO", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.n), &(all->game));
	else if (ft_strnstr(res[0], "SO", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.s), &(all->game));
	else if (ft_strnstr(res[0], "WE", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.w), &(all->game));
	else if (ft_strnstr(res[0], "EA", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.e), &(all->game));
	else if (ft_strnstr(res[0], "S", len_id) && (len_id == 1) && (len == 2))
		ft_put_image(res[1], &(all->game.sp), &(all->game));
	else if (ft_strnstr(res[0], "F", len_id) && (len_id == 1) && (len == 2))
		ft_put_color(res[1], all->game.f, &(all->game));
	else if (ft_strnstr(res[0], "C", len_id) && (len_id == 1) && (len == 2))
		ft_put_color(res[1], all->game.c, &(all->game));
}
