/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/24 17:37:39 by yeslee           ###   ########.fr       */
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

void	mlx_start(t_all *all)
{
	ft_load_texture(&(all->info));
	all->info.win = mlx_new_window(
		all->info.mlx, all->game.r.width, all->game.r.height, "yeslee_cub3D");
	all->info.img.img = mlx_new_image(all->info.mlx, all->game.r.width, all->game.r.height);
	all->info.img.data = (int *)mlx_get_data_addr(all->info.img.img, &(all->info.img.bpp), &(all->info.img.size_l), &(all->info.img.endian));
	mlx_loop_hook(all->info.mlx, &main_loop, &(all->info));
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &key_press, &(all->info));
	mlx_loop(all->info.mlx);
}

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
	if (!(all.map.cnt_exist))
		ft_error_message(7);
	ft_map_validation(&all);
	close(fd);
	mlx_start(&all);
	return (0);
}
