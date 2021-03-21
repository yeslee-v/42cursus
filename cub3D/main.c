/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/21 23:22:20 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_all	all;
	int		i;
	int		j;

	ft_init_start(ac, av, &all);
	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			ft_read_line(line, &all);
		//	free(line);
		}
	}
	ft_map_validation(&all);
/*	printf("\n[window_size]\nw: %d h: %d\n\n", all.game.r.width, all.game.r.height);
	printf("[img]\nn: %s\ns: %s\nw: %s\ne: %s\nsp: %s\n\n",
			all.game.n,
			all.game.s,
			all.game.w,
			all.game.e,
			all.game.sp);
	printf("[color_f]\n%d %d %d\n\n", all.game.f[0], all.game.f[1], all.game.f[2]);
	printf("[color_c]\n%d %d %d\n\n", all.game.c[0], all.game.c[1], all.game.c[2]);*/
	i = 0;
	while (i < all.map.row)
	{
		j = 0;
		printf("[%d] ", i);
		while (j < all.map.col)
		{
			printf("%d ", all.map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	if (!(all.map.cnt_exist))
		ft_error_message(7);
	close(fd);
	//	free(line);
	return (0);
}
