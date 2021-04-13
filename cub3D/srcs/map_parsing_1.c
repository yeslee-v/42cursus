/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/13 15:11:21 by yeslee           ###   ########.fr       */
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

void	ft_read_line(char *line, t_all *all)
{
	if (all->game.cnt == 8)
		ft_read_map(line, all);
	else
	{
		if (ft_isspace(line[0]))
			ft_error_message(5);
		if ((line[0] == 'R') && (ft_isspace(line[1])))
			ft_put_size((line + 2), &(all->game));
		else if ((line[0] == 'N') && (line[1] == 'O') && (ft_isspace(line[2])))
			ft_put_image((line + 3), &(all->game.n), &(all->game));
		else if ((line[0] == 'S') && (line[1] == 'O') && (ft_isspace(line[2])))
			ft_put_image((line + 3), &(all->game.s), &(all->game));
		else if ((line[0] == 'W') && (line[1] == 'E') && (ft_isspace(line[2])))
			ft_put_image((line + 3), &(all->game.e), &(all->game));
		else if ((line[0] == 'E') && (line[1] == 'A') && (ft_isspace(line[2])))
			ft_put_image((line + 3), &(all->game.w), &(all->game));
		else if ((line[0] == 'S') && (ft_isspace(line[1])))
			ft_put_image((line + 2), &(all->game.sp), &(all->game));
		else if ((line[0] == 'F') && (ft_isspace(line[1])))
			ft_put_color((line + 2), all->game.f, &(all->game));
		else if ((line[0] == 'C') && (ft_isspace(line[1])))
			ft_put_color((line + 2), all->game.c, &(all->game));
		else
			ft_error_message(6);
	}
}
