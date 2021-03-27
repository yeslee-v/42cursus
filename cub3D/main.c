/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/26 17:26:29 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_start(int ac, char **av, t_all *all)
{
	ft_t_info_init(all);
	ft_t_game_init(&(all->game));
	ft_t_map_init(&(all->map));
	ft_t_save_init_on(ac, av, (&(all->save)));
}

void	ft_map_parsing_intro(int ac, char **av, t_all *all)
{
	int		fd;
	char	*line;

	ft_init_start(ac, av, all);
	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			ft_read_line(line, all);
			free(line);
		}
	}
	if (!(all->map.cnt_exist))
		ft_error_message(7);
	ft_map_validation(all);
	close(fd);

}

int	main(int ac, char **av)
{
	t_all	all;
	
	ft_map_parsing_intro(ac, av, &all);
	ft_mlx_start(&all);
	return (0);
}
