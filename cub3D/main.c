/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/16 20:47:08 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_map_validation(&all);
	if (!(all.map.cnt_exist))
		ft_error_message(8);
	close(fd);
//	free(line);
	return (0);
}
