/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:58:03 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/01 20:36:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	ft_calc_save_map(t_all *all)
{
	int x;
	ft_allocate_buf(all);
	ft_paint_f_c(all);

	x = 0;
    while (x < all->game.r.width)
    {
		ft_allocate_buf_for_texture(all);
		ft_calc_save_init(all, x);
        ft_put_step_side_value(all);
		ft_dda(all);
		ft_draw_wall(all);
		ft_paint_texture(all, x);
		all->sp_buf.zBuffer[x] = all->info.perpWallDist;
        x++;
    }
	return (0);
}

int ft_main_loop(t_all *all)
{
	ft_calc_save_map(all);
    ft_img_draw(all);
	ft_sprite_loop(all);

    return (0);
}

int ft_mlx_intro(t_all *all)
{
    all->info.mlx = mlx_init();
	ft_set_screen_size(all);
	ft_allocate_texture(all);
    load_texture(all);

	all->info.win = mlx_new_window(all->info.mlx, all->game.r.width,
			all->game.r.height, "mlx");
	all->img.img = mlx_new_image(all->info.mlx, all->game.r.width,
			all->game.r.height);
	all->img.data = (int *)mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.size_l, &all->img.endian);

	mlx_loop_hook(all->info.mlx, &ft_main_loop, all);
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &ft_press_key, all);
	mlx_hook(all->info.win, X_EVENT_KEY_EXIT, 17, &ft_close, all);
	ft_bgm_start();
    mlx_loop(all->info.mlx);
	if (!(&ft_main_loop))
		ft_bgm_end();
	return (0);
}
