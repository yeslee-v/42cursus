/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:14:52 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/12 17:15:11 by yeslee           ###   ########.fr       */
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
