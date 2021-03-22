/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/23 00:57:09 by yeslee           ###   ########.fr       */
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
			free(line);
		}
	}
	ft_map_validation(&all);
	i = 0;
	while (i < all.map.row)
	{
		j = 0;
		while (j < all.map.col)
		{
			printf("%d ", all.map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	if (!(all.map.cnt_exist))
	{
		ft_error_message(7);
	}
	close(fd);
	all.info.win = mlx_new_window(
		all.info.mlx, all.game.r.width, all.game.r.height, "yeslee_cub3D");
	return (0);
}
