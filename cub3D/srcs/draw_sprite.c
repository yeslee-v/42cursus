/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:32:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/05 21:41:32 by yeslee           ###   ########.fr       */
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

/*void	ft_sprite_init(t_all *all)
{
}*/

int	ft_sprite_loop(t_all *all)
{
	int i;

	i = 0;
	while (i < all->map.num_sp)
    {
      all->sp_buf.spriteOrder[i] = i;
      all->sp_buf.spriteDistance[i] = ((all->info.posX - all->sp_buf.sprite[i].x) *
			  (all->info.posX - all->sp_buf.sprite[i].x) + (all->info.posY - all->sp_buf.sprite[i].y) *
			  (all->info.posY - all->sp_buf.sprite[i].y));
	  i++;
    }
    ft_sort_sprite(all->sp_buf.spriteOrder, all->sp_buf.spriteDistance, all->map.num_sp);

	i = 0;
	while (i < all->map.num_sp)
    {
      double spriteX = all->sp_buf.sprite[all->sp_buf.spriteOrder[i]].x - all->info.posX;
      double spriteY = all->sp_buf.sprite[all->sp_buf.spriteOrder[i]].y - all->info.posY;

      double invDet = 1.0 / (all->info.planeX * all->info.dirY - all->info.dirX * all->info.planeY);

      double transformX = invDet * (all->info.dirY * spriteX - all->info.dirX * spriteY);
      double transformY = invDet * (-all->info.planeY * spriteX + all->info.planeX * spriteY);

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
		//if(transformY > 0 && stripe > 0 && stripe < all->game.r.width && transformY < all->sp_buf.zBuffer[stripe])
		if(transformY > 0 && stripe > 0 && stripe < all->game.r.width)
		{
			int dy = drawStartY; 
			while (dy < drawEndY)
       		{
				int d = (dy) * 256 - all->game.r.height * 128 + spriteHeight * 128;
				int texY = ((d * all->info.texHeight) / spriteHeight) / 256;
				all->info.color = all->info.tex[4][all->info.texWidth * texY + texX];
				printf("color: %d\n", all->info.color);
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
