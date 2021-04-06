/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:38:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/06 18:34:25 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_press_esc(int key, t_all *all)
{
	if (key == KEY_ESC)
	{
		ft_bgm_end();
		exit(0);
	}
	return (0);
}

int	ft_press_arrow(int key, t_all *all, double old_dirx, double old_planex)
{
	if (key == KEY_ARROW_L)
	{
		all->info.dirX = all->info.dirX * cos(all->info.rotSpeed) -
			all->info.dirY * sin(all->info.rotSpeed);
		all->info.dirY = old_dirx * sin(all->info.rotSpeed) +
			all->info.dirY * cos(all->info.rotSpeed);
		all->info.planeX = all->info.planeX * cos(all->info.rotSpeed) -
			all->info.planeY * sin(all->info.rotSpeed);
		all->info.planeY = old_planex * sin(all->info.rotSpeed) +
			all->info.planeY * cos(all->info.rotSpeed);
	}
	if (key == KEY_ARROW_R)
	{
		all->info.dirX = all->info.dirX * cos(-all->info.rotSpeed) -
			all->info.dirY * sin(-all->info.rotSpeed);
		all->info.dirY = old_dirx * sin(-all->info.rotSpeed) +
			all->info.dirY * cos(-all->info.rotSpeed);
		all->info.planeX = all->info.planeX * cos(-all->info.rotSpeed) -
			all->info.planeY * sin(-all->info.rotSpeed);
		all->info.planeY = old_planex * sin(-all->info.rotSpeed) +
			all->info.planeY * cos(-all->info.rotSpeed);
	}
	return (0);
}

int	ft_press_key_ad(int key, t_all *all, double vec_x, double vec_y)
{
	double old_pos_x;

	old_pos_x = all->info.posX;
	if (key == KEY_A)
	{
		if (all->map.map[(int)(all->info.posX - vec_y)]
				[(int)(all->info.posY)] != '1')
			all->info.posX -= vec_y;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.posY + vec_x)] != '1')
			all->info.posY += vec_x;
	}
	else if (key == KEY_D)
	{
		if (all->map.map[(int)(all->info.posX + vec_y)]
				[(int)(all->info.posY)] != '1')
			all->info.posX += vec_y;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.posY - vec_x)] != '1')
			all->info.posY -= vec_x;
	}
	return (0);
}

int	ft_press_key_ws(int key, t_all *all, double vec_x, double vec_y)
{
	double old_pos_x;

	old_pos_x = all->info.posX;
	if (key == KEY_W)
	{
		if (all->map.map[(int)(all->info.posX + vec_x)]
				[(int)(all->info.posY)] != '1')
			all->info.posX += vec_x;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.posY + vec_y)] != '1')
			all->info.posY += vec_y;
	}
	if (key == KEY_S)
	{
		if (all->map.map[(int)(all->info.posX - vec_x)]
				[(int)(all->info.posY)] != '1')
			all->info.posX -= vec_x;
		if (all->map.map[(int)old_pos_x]
				[(int)(all->info.posY - vec_y)] != '1')
			all->info.posY -= vec_y;
	}
	return (0);
}

int	ft_press_key(int key, t_all *all)
{
	double	vec_x;
	double	vec_y;
	double	old_dirx;
	double	old_planex;

	old_dirx = all->info.dirX;
	old_planex = all->info.planeX;
	vec_x = all->info.dirX * all->info.moveSpeed;
	vec_y = all->info.dirY * all->info.moveSpeed;
	ft_press_key_ws(key, all, vec_x, vec_y);
	ft_press_key_ad(key, all, vec_x, vec_y);
	ft_press_arrow(key, all, old_dirx, old_planex);
	ft_press_esc(key, all);
	ft_main_loop(all);
	return (0);
}
