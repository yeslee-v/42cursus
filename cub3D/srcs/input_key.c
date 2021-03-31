/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:38:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/31 18:55:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_press_key(int key, t_all *all)
{
	//map_x
    if (key == KEY_W)
    {
        if (all->map.map[(int)(all->info.posX + all->info.dirX * all->info.moveSpeed)][(int)(all->info.posY)] != '1')
            all->info.posX += all->info.dirX * all->info.moveSpeed;
        if (all->map.map[(int)(all->info.posX)][(int)(all->info.posY + all->info.dirY * all->info.moveSpeed)] != '1')
            all->info.posY += all->info.dirY * all->info.moveSpeed;
    }

    if (key == KEY_S)
    {
        if (all->map.map[(int)(all->info.posX - all->info.dirX * all->info.moveSpeed)][(int)(all->info.posY)] != '1')
            all->info.posX -= all->info.dirX * all->info.moveSpeed;
        if (all->map.map[(int)(all->info.posX)][(int)(all->info.posY - all->info.dirY * all->info.moveSpeed)] != '1')
            all->info.posY -= all->info.dirY * all->info.moveSpeed;
    }

    if (key == KEY_D)
    {
        if (all->map.map[(int)(all->info.posX + all->info.dirY * all->info.moveSpeed)][(int)(all->info.posY)] != '1')
            all->info.posX += all->info.dirY * all->info.moveSpeed;
        if (all->map.map[(int)(all->info.posX)][(int)(all->info.posY - all->info.dirX * all->info.moveSpeed)] != '1')
            all->info.posY -= all->info.dirX * all->info.moveSpeed;
    }

    if (key == KEY_A)
    {
        if (all->map.map[(int)(all->info.posX - all->info.dirY * all->info.moveSpeed)][(int)(all->info.posY)] != '1')
            all->info.posX -= all->info.dirY * all->info.moveSpeed;
        if (all->map.map[(int)(all->info.posX)][(int)(all->info.posY + all->info.dirX * all->info.moveSpeed)] != '1')
            all->info.posY += all->info.dirX * all->info.moveSpeed;
    }

    if (key == KEY_ARROW_L)
    {
        double oldDirectionX = all->info.dirX;
        all->info.dirX = all->info.dirX * cos(all->info.rotSpeed) - all->info.dirY * sin(all->info.rotSpeed);
        all->info.dirY = oldDirectionX * sin(all->info.rotSpeed) + all->info.dirY * cos(all->info.rotSpeed);
        double oldPlaneX = all->info.planeX;
        all->info.planeX = all->info.planeX * cos(all->info.rotSpeed) - all->info.planeY * sin(all->info.rotSpeed);
        all->info.planeY = oldPlaneX * sin(all->info.rotSpeed) + all->info.planeY * cos(all->info.rotSpeed);
    }

    if (key == KEY_ARROW_R)
    {
        double oldDirectionX = all->info.dirX;
        all->info.dirX = all->info.dirX * cos(-all->info.rotSpeed) - all->info.dirY * sin(-all->info.rotSpeed);
        all->info.dirY = oldDirectionX * sin(-all->info.rotSpeed) + all->info.dirY * cos(-all->info.rotSpeed);
        double oldPlaneX = all->info.planeX;
        all->info.planeX = all->info.planeX * cos(-all->info.rotSpeed) - all->info.planeY * sin(-all->info.rotSpeed);
        all->info.planeY = oldPlaneX * sin(-all->info.rotSpeed) + all->info.planeY * cos(-all->info.rotSpeed);
    }
    if (key == KEY_ESC)
	{
		ft_bgm_end();
        exit(0);
	}
    return (0);
}

int		ft_close(int key, t_all *all)
{
	ft_bgm_end();
	exit(0);
	return (0);
}
