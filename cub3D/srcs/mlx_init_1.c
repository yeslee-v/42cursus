/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:45:32 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/12 11:48:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_press_ne_key(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == 'N')
	{
		all->info.dir_x = -1.0;
		all->info.dir_y = 0.0;
		all->info.plane_x = 0.0;
		all->info.plane_y = 0.66;
	}
	if (all->map.map[i][j] == 'E')
	{
		all->info.dir_x = 0.0;
		all->info.dir_y = 1.0;
		all->info.plane_x = 0.66;
		all->info.plane_y = 0.0;
	}
}

void	ft_press_sw_key(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == 'S')
	{
		all->info.dir_x = 1.0;
		all->info.dir_y = 0.0;
		all->info.plane_x = 0.0;
		all->info.plane_y = -0.66;
	}
	if (all->map.map[i][j] == 'W')
	{
		all->info.dir_x = 0.0;
		all->info.dir_y = -1.0;
		all->info.plane_x = -0.66;
		all->info.plane_y = 0.0;
	}
}

void	ft_nesw_init(t_all *all, int i, int j)
{
	ft_press_ne_key(all, i, j);
	ft_press_sw_key(all, i, j);
}
