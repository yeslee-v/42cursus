/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:38:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 12:00:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press_esc(int key)
{
	if (key == KEY_ESC)
	{
		//ft_bgm_end();
		exit(0);
	}
	return (0);
}

int	ft_press_arrow(int key, t_all *all, double old_dirx, double old_planex)
{
	if (key == KEY_ARROW_L)
	{
		all->info.dir_x = all->info.dir_x * cos(all->info.rot_s) -
			all->info.dir_y * sin(all->info.rot_s);
		all->info.dir_y = old_dirx * sin(all->info.rot_s) +
			all->info.dir_y * cos(all->info.rot_s);
		all->info.plane_x = all->info.plane_x * cos(all->info.rot_s) -
			all->info.plane_y * sin(all->info.rot_s);
		all->info.plane_y = old_planex * sin(all->info.rot_s) +
			all->info.plane_y * cos(all->info.rot_s);
	}
	if (key == KEY_ARROW_R)
	{
		all->info.dir_x = all->info.dir_x * cos(-all->info.rot_s) -
			all->info.dir_y * sin(-all->info.rot_s);
		all->info.dir_y = old_dirx * sin(-all->info.rot_s) +
			all->info.dir_y * cos(-all->info.rot_s);
		all->info.plane_x = all->info.plane_x * cos(-all->info.rot_s) -
			all->info.plane_y * sin(-all->info.rot_s);
		all->info.plane_y = old_planex * sin(-all->info.rot_s) +
			all->info.plane_y * cos(-all->info.rot_s);
	}
	return (0);
}

int	ft_press_key_ad(int key, t_all *all, double vec_x, double vec_y)
{
	double old_pos_x;

	old_pos_x = all->info.pos_x;
	if (key == KEY_A)
	{
		if (all->map.map[(int)(all->info.pos_x - vec_y)]
				[(int)(all->info.pos_y)] != '1')
			all->info.pos_x -= vec_y;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.pos_y + vec_x)] != '1')
			all->info.pos_y += vec_x;
	}
	else if (key == KEY_D)
	{
		if (all->map.map[(int)(all->info.pos_x + vec_y)]
				[(int)(all->info.pos_y)] != '1')
			all->info.pos_x += vec_y;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.pos_y - vec_x)] != '1')
			all->info.pos_y -= vec_x;
	}
	return (0);
}

int	ft_press_key_ws(int key, t_all *all, double vec_x, double vec_y)
{
	double old_pos_x;

	old_pos_x = all->info.pos_x;
	if (key == KEY_W)
	{
		if (all->map.map[(int)(all->info.pos_x + vec_x)]
				[(int)(all->info.pos_y)] != '1')
			all->info.pos_x += vec_x;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.pos_y + vec_y)] != '1')
			all->info.pos_y += vec_y;
	}
	if (key == KEY_S)
	{
		if (all->map.map[(int)(all->info.pos_x - vec_x)]
				[(int)(all->info.pos_y)] != '1')
			all->info.pos_x -= vec_x;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.pos_y - vec_y)] != '1')
			all->info.pos_y -= vec_y;
	}
	return (0);
}

int	ft_press_key(int key, t_all *all)
{
	double	vec_x;
	double	vec_y;
	double	old_dirx;
	double	old_planex;

	old_dirx = all->info.dir_x;
	old_planex = all->info.plane_x;
	vec_x = all->info.dir_x * all->info.move_s;
	vec_y = all->info.dir_y * all->info.move_s;
	ft_press_key_ws(key, all, vec_x, vec_y);
	ft_press_key_ad(key, all, vec_x, vec_y);
	ft_press_arrow(key, all, old_dirx, old_planex);
	ft_press_esc(key);
	ft_main_loop(all);
	return (0);
}
