/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:32:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/06 14:15:17 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort_sprite(int *buf1, double *buf2, int num)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num - 1)
		{
			if (buf2[j + 1] > buf2[j])
			{
				temp = buf2[j];
				buf2[j] = buf2[j + 1];
				buf2[j + 1] = temp;
				temp = buf1[j];
				buf1[j] = buf1[j + 1];
				buf1[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_sprite_init(t_all *all)
{
	int i;

	i = 0;
	while (i < all->map.num_sp)
    {
      all->sp.spriteOrder[i] = i;
      all->sp.spriteDistance[i] = ((all->info.posX - all->sp.sprite[i].x) *
			  (all->info.posX - all->sp.sprite[i].x) + (all->info.posY - all->sp.sprite[i].y) *
			  (all->info.posY - all->sp.sprite[i].y));
	  i++;
    }
    ft_sort_sprite(all->sp.spriteOrder, all->sp.spriteDistance, all->map.num_sp);
}

int	ft_sprite_loop(t_all *all)
{
	int i;
	
	ft_sort_sprite_init(all);
	i = 0;
	while (i < all->map.num_sp)
    {
      all->sp.sp_x = all->sp.sprite[all->sp.spriteOrder[i]].x - all->info.posX;
      all->sp.sp_y = all->sp.sprite[all->sp.spriteOrder[i]].y - all->info.posY;

      double invDet = 1.0 / (all->info.planeX * all->info.dirY - all->info.dirX * all->info.planeY);

      double transformX = invDet * (all->info.dirY * all->sp.sp_x - all->info.dirX * all->sp.sp_y);
      double transformY = invDet * (-all->info.planeY * all->sp.sp_x + all->info.planeX * all->sp.sp_y);

      int spriteScreenX = (int)((all->game.r.width / 2) * (1 + transformX / transformY));

      int spriteHeight = abs((int)(all->game.r.height / (transformY)));
      int drawStartY = -spriteHeight / 2 + all->game.r.height / 2;
      if(drawStartY < 0)
		  drawStartY = 0;
      int drawEndY = spriteHeight / 2 + all->game.r.height / 2;
      if(drawEndY >= all->game.r.height)
		  drawEndY = all->game.r.height - 1;

      int spriteWidth = abs((int)(all->game.r.height / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0)
		  drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= all->game.r.width)
		  drawEndX = all->game.r.width - 1;

	  int stripe = drawStartX;
	  while (stripe < drawEndX)
      {
		  int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * all->info.texWidth / spriteWidth) / 256;
		if(transformY > 0 && stripe > 0 && stripe < all->game.r.width && transformY < all->sp.zBuffer[stripe])
		{
			int dy = drawStartY; 
			while (dy < drawEndY)
       		{
				int d = (dy) * 256 - all->game.r.height * 128 + spriteHeight * 128;
				int texY = ((d * all->info.texHeight) / spriteHeight) / 256;
				all->info.color = all->info.tex[4][all->info.texWidth * texY + texX];
          		if ((all->info.color & 0x00FFFFFF) != 0)
					all->info.buf[dy][stripe] = all->info.color;
				dy++;
        	}
		}
		stripe++;
      }
	  i++;
    }
	ft_img_draw(all);
	int y = 0;
	while (y < all->game.r.height)
	{
		int x = 0;
		while (x < all->game.r.width)
		{
			all->info.buf[y][x] = 0;
			x++;
		}
		y++;
	}
	return (0);
}
