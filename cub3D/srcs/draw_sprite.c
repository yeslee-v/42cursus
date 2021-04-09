/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:32:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 11:46:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_set_sprite_1(t_all *all, int i)
{
	all->sp.sp_x = all->sp.sprite[all->sp.sp_order[i]].x - all->info.pos_x;
	all->sp.sp_y = all->sp.sprite[all->sp.sp_order[i]].y - all->info.pos_y;
	all->sp.inv_det = 1.0 /
		(all->info.plane_x * all->info.dir_y - all->info.dir_x * all->info.plane_y);
	all->sp.tran_x = all->sp.inv_det *
		(all->info.dir_y * all->sp.sp_x - all->info.dir_x * all->sp.sp_y);
	all->sp.tran_y = all->sp.inv_det *
		(-all->info.plane_y * all->sp.sp_x + all->info.plane_x * all->sp.sp_y);
	all->sp.sp_scx =
		(int)((all->game.r.width / 2) * (1 + all->sp.tran_x / all->sp.tran_y));
	all->sp.sp_h = abs((int)(all->game.r.height / (all->sp.tran_y)));
	all->sp.start_dy = -all->sp.sp_h / 2 + all->game.r.height / 2;
	return (i);
}

void	ft_set_sprite_2(t_all *all)
{
	if (all->sp.start_dy < 0)
		all->sp.start_dy = 0;
	all->sp.end_dy = all->sp.sp_h / 2 + all->game.r.height / 2;
	if (all->sp.end_dy >= all->game.r.height)
		all->sp.end_dy = all->game.r.height - 1;
	all->sp.sp_w = abs((int)(all->game.r.height / (all->sp.tran_y)));
	all->sp.start_dx = -all->sp.sp_w / 2 + all->sp.sp_scx;
	if (all->sp.start_dx < 0)
		all->sp.start_dx = 0;
	all->sp.end_dx = all->sp.sp_w / 2 + all->sp.sp_scx;
	if (all->sp.end_dx >= all->game.r.width)
		all->sp.end_dx = all->game.r.width - 1;
	all->sp.stripe = all->sp.start_dx;
}

void	ft_paint_sprite(t_all *all)
{
	int	dy;
	int	d;

	while (all->sp.stripe < all->sp.end_dx)
	{
		all->sp.tex_x = (int)(256 * (all->sp.stripe -
					(-all->sp.sp_w / 2 + all->sp.sp_scx)) * all->info.tex_w
				/ all->sp.sp_w) / 256;
		if (all->sp.tran_y > 0 && all->sp.stripe > 0 &&
			all->sp.stripe < all->game.r.width &&
			all->sp.tran_y < all->sp.z_buf[all->sp.stripe])
		{
			dy = all->sp.start_dy;
			while (dy < all->sp.end_dy)
			{
				d = (dy)*256 - all->game.r.height * 128 + all->sp.sp_h * 128;
				all->sp.tex_y = ((d * all->info.tex_h) / all->sp.sp_h) / 256;
				all->info.color =
					all->info.tex[4][all->info.tex_w * all->sp.tex_y + all->sp.tex_x];
				if ((all->info.color & 0x00FFFFFF) != 0)
					all->info.buf[dy][all->sp.stripe] = all->info.color;
				dy++;
			}
		}
		all->sp.stripe++;
	}
}

void	ft_clean_buffer(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->game.r.height)
	{
		x = 0;
		while (x < all->game.r.width)
		{
			all->info.buf[y][x] = 0;
			x++;
		}
		y++;
	}
}

int		ft_sprite_loop(t_all *all)
{
	int	i;

	ft_sort_sprite_init(all);
	i = 0;
	while (i < all->map.num_sp)
	{
		i = ft_set_sprite_1(all, i);
		ft_set_sprite_2(all);
		ft_paint_sprite(all);
		i++;
	}
	ft_img_draw(all);
	ft_clean_buffer(all);
	return (0);
}
