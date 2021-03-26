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
//	ft_t_info_init(all);
	ft_t_game_init(&(all->game));
	ft_t_map_init(&(all->map));
	ft_t_save_init_on(ac, av, (&(all->save)));
}

/*void	ft_my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char *dst;

	dst = all->info.img.addr + (y * all->info.img.size_l + x *
			(all->info.img.bpp / 8));
	*(unsigned int *)dst = color;
}*/

/*void	ft_mlx_start(t_all *all)
{
	all->info.mlx = mlx_init();
//	ft_load_texture(&(all->info));
	all->info.win = mlx_new_window(
		all->info.mlx, all->game.r.width, all->game.r.height, "yelled");
//	all->info.img.img = mlx_new_image(all->info.mlx, all->game.r.width, all->game.r.height);
//	all->info.img.addr = mlx_get_data_addr(all->info.img.img,
//			&all->info.img.bpp, &all->info.img.size_l,
//			&all->info.img.endian);
//	ft_my_mlx_pixel_put(all, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(all->info.mlx, all->info.win, all->info.img.img, 0, 0);
	mlx_loop_hook(all->info.mlx, &main_loop, &(all->info));
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &key_press, &(all->info));
	mlx_loop(all->info.mlx);
}*/

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

int	main_intro(int ac, char **av)
{
	t_all	all;
	
	ft_map_parsing_intro(ac, av, &all);
//	ft_mlx_start(&all);
	return (0);
}
