/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/11 18:35:29 by yeslee           ###   ########.fr       */
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

//void	ft_parse_space(char *line, t_all *all)
//{
/*	int		len;
	int		len_id;
	char	**res;*/

	/*res = ft_split(line, ' ');
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
	ft_free_char(res);*/
//}

void	ft_read_line(char *line, t_all *all)
{
	if (all->game.cnt == 8)
		ft_read_map(line, all);
	else if (ft_isspace(line[0]))
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
		ft_put_color((line + 2), &(all->game.f), &(all->game));
	else if ((line[0] == 'C') && (ft_isspace(line[1])))
		ft_put_color((line + 2), &(all->game.c), &(all->game));
	printf("[R] %d %d\n", all->game.r.width, all->game.r.height);
	printf("[NO] %s\n", all->game.n);
	printf("[SO] %s\n", all->game.s);
	printf("[WE] %s\n", all->game.e);
	printf("[EA] %s\n", all->game.w);
	printf("[S] %s\n", all->game.sp);
	printf("[F] %d %d %d\n", all->game.f[0], all->game.f[1], all->game.f[2]);
	printf("[C] %d %d %d\n", all->game.c[0], all->game.c[1], all->game.c[2]);
	printf("[cnt] %d\n", all->game.cnt);
	printf("=========================================\n");
}
