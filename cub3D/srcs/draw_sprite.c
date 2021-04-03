/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:32:14 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/03 23:46:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sort_sprite(int *buf1, double *buf2, int num)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if (buf2[j] < buf2[i])
			{
				printf("loaded\n");
				temp = buf2[j];
				buf2[j] = buf2[i];
				buf2[i] = temp;
				temp = buf1[j];
				buf1[j] = buf1[i];
				buf1[i] = temp;
				printf("[%d:%d] %f %f %d %d\n", i, j, buf2[j], buf2[i], buf1[j], buf1[i]);
			}
			j++;
		}
		i++;
	}
}

int	ft_sprite_loop(t_all *all)
{
	for(int i = 0; i < all->map.num_sp; i++)
    {
      all->sp_buf.spriteOrder[i] = i;
      all->sp_buf.spriteDistance[i] = ((all->info.posX - all->sp_buf.sprite.x) *
			  (all->info.posX - all->sp_buf.sprite.x) + (all->info.posY - all->sp_buf.sprite.y) *
			  (all->info.posY - all->sp_buf.sprite.y));
    }
    ft_sort_sprite(all->sp_buf.spriteOrder, all->sp_buf.spriteDistance, all->map.num_sp);

    //after sorting the sprites, do the projection and draw them
/*    for(int i = 0; i < all->map.num_sp; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = sprite[all->sp_buf.spriteOrder[i]].x - all->info.posX;
      double spriteY = sprite[all->sp_buf.spriteOrder[i]].y - all->info.posY;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

      double transformX = invDet * (dirY * spriteX - dirX * spriteY);
      double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

      //calculate height of the sprite on screen
      int spriteHeight = abs(int(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + h / 2;
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + h / 2;
      if(drawEndY >= h) drawEndY = h - 1;

      //calculate width of the sprite
      int spriteWidth = abs( int (h / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= w) drawEndX = w - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * texHeight) / spriteHeight) / 256;
          Uint32 color = texture[sprite[all->sp_buf.spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
        }
      }
    }
	drawBuffer(buffer[0]);
    for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()*/
	return (0);
}
