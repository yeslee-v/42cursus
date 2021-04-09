/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:53:10 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 11:48:50 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_step_side_value(t_all *all)
{
	if (all->info.ray_x < 0)
	{
		all->info.step_x = -1;
		all->info.side_x = (all->info.pos_x - all->info.map_x) * all->info.delta_x;
	}
	else
	{
		all->info.step_x = 1;
		all->info.side_x = (all->info.map_x + 1.0 - all->info.pos_x) * all->info.delta_x;
	}
	if (all->info.ray_y < 0)
	{
		all->info.step_y = -1;
		all->info.side_y = (all->info.pos_y - all->info.map_y) * all->info.delta_y;
	}
	else
	{
		all->info.step_y = 1;
		all->info.side_y = (all->info.map_y + 1.0 - all->info.pos_y) * all->info.delta_y;
	}
}

void	ft_dda(t_all *all)
{
	while (all->info.hit == 0)
	{
		if (all->info.side_x < all->info.side_y)
		{
			all->info.side_x += all->info.delta_x;
			all->info.map_x += all->info.step_x;
			all->info.side = 0;
		}
		else
		{
			all->info.side_y += all->info.delta_y;
			all->info.map_y += all->info.step_y;
			all->info.side = 1;
		}
		if (all->map.map[all->info.map_x][all->info.map_y] == '1')
			all->info.hit = 1;
	}
}

void	ft_draw_wall(t_all *all)
{
	if (all->info.side == 0)
		all->info.perp = (all->info.map_x - all->info.pos_x + 
				(1.0 - all->info.step_x) / 2.0) / all->info.ray_x;
	else
		all->info.perp = (all->info.map_y - all->info.pos_y +
				(1.0 - all->info.step_y) / 2.0) / all->info.ray_y;
	all->info.line_h = (int)(all->game.r.height / all->info.perp);
	all->info.draw_s = (-all->info.line_h / 2) + (all->game.r.height / 2);
	if (all->info.draw_s < 0)
		all->info.draw_s = 0;
	all->info.draw_e = (all->info.line_h / 2) + (all->game.r.height / 2);
	if (all->info.draw_e >= all->game.r.height)
		all->info.draw_e = all->game.r.height - 1;
	all->info.tex_n = ft_set_texnum(all);
	
	if (all->info.side == 0)
		all->info.wall_x = all->info.pos_y + all->info.perp * all->info.ray_y;
	else
        all->info.wall_x = all->info.pos_x + all->info.perp * all->info.ray_x;
	all->info.wall_x -= floor(all->info.wall_x);
}

void	ft_paint_texture(t_all *all, int x)
{
	all->info.tex_x = (int)(all->info.wall_x * (double)all->info.tex_w);
	if (all->info.side == 0 && all->info.ray_x > 0)
		all->info.tex_x = all->info.tex_w - all->info.tex_x - 1;
	if (all->info.side == 1 && all->info.ray_y < 0)
		all->info.tex_x = all->info.tex_w - all->info.tex_x - 1;

	all->info.step = 1.0 * all->info.tex_h / all->info.line_h;
	all->info.tex_pos = (all->info.draw_s - all->game.r.height / 2.0 + all->info.line_h / 2.0) * all->info.step;
	
	int y;
	y = all->info.draw_s; 
	while (y < all->info.draw_e)
	{
		all->info.tex_y = (int)all->info.tex_pos & (all->info.tex_h - 1);
		all->info.tex_pos += all->info.step;
		all->info.color = all->info.tex[all->info.tex_n][all->info.tex_h * all->info.tex_y + all->info.tex_x];
		if (all->info.side == 1)
			all->info.color = (all->info.color >> 1) & 8355711;
		all->info.buf[y][x] = all->info.color;
		all->img.data[y * all->img.size_l / all->img.bpp * 8 + x] = all->info.buf[y][x];
		y++;
	}
}
