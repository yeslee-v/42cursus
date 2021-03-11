/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/11 22:11:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_space_on(char *line)
{
	char	**res;

	res = NULL;
	if (ft_strchr(line, ' '))
		res = ft_split(line, ' ');
	else if (ft_strchr(line, ','))
		res = ft_split(line, ',');
	else
		ft_error_message(5);
	return (res);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_all	all;

	ft_t_game_init(&(all.game));
	ft_t_map_init(&(all.map));
	ft_t_save_init_on(ac, av, &(all.save));

	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line))
		{
			ft_read_line(line, &all);
			free(line);
		}
	}
/*	printf("\n[window_size]\nw: %d h: %d\n\n", all.game.r.width, all.game.r.height);
	printf("[img]\nn: %s\ns: %s\nw: %s\ne: %s\nsp: %s\n\n", all.game.n, all.game.s,
			all.game.w, all.game.e, all.game.sp);
	printf("[color_f]\n%d %d %d\n\n", all.game.f[0], all.game.f[1],
			all.game.f[2]);
	printf("[color_c]\n%d %d %d\n\n", all.game.c[0], all.game.c[1],
			all.game.c[2]);
	printf("[map_size]\nrow: %d col:%d\n", all.map.row, all.map.col);*/
	close(fd);
	free(line);
	return (0);
}
