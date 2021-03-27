# include "cub3d.h"

void imageDraw(t_info *info, t_all *all)
{
    for (int y = 0; y < all->game.r.height; y++)
        for (int x = 0; x < all->game.r.width; x++)
            info->img.data[y * all->game.r.width + x] = info->buf[y][x];

    mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int calculateAndSaveToMap(t_info *info, t_all *all)
{
	int i;

	i = 0;
	info->buf = ft_calloc(sizeof(int *), all->game.r.width);
	if (!(info->buf))
		return (0);
	while (i < all->game.r.width)
	{
		info->buf[i] = ft_calloc(sizeof(int), all->game.r.height);
		if (!(info->buf[i]))
		{
			ft_free_all_int(info->buf, i);
			return (0);
		}
		i++;
	}
	for (int x = 0; x < all->game.r.width; x++)
    {
        for (int y = 0; y < all->game.r.height; y++)
        {
            info->buf[y][x] = 0xFFFFFF; 
            info->buf[all->game.r.height - y - 1][x] = 0x000000;
        }
    }

	printf("loaded\n");
	int  x = 0;
    while (x < all->game.r.width)
    {
        double cameraX = (2 * x / (double)(all->game.r.width)) - 1;
        double rayDirectionX = info->dirX + info->planeX * cameraX;
        double rayDirectionY = info->dirY + info->planeY * cameraX;

        int mapX = (int)(info->posX);
        int mapY = (int)(info->posY);

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirectionX);
        double deltaDistY = fabs(1 / rayDirectionY);

        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;
        
		if (rayDirectionX < 0)
        {
            stepX = -1;
            sideDistX = (info->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
        }
        if (rayDirectionY < 0)
        {
            stepY = -1;
            sideDistY = (info->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
        }
        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (all->map.map[mapX][mapY] > 0)
                hit = 1;
        }
        if (side == 0)
            perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirectionX;
        else
            perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirectionY;

        int lineHeight = (int)(all->game.r.height / perpWallDist);
        int drawStart = (-lineHeight / 2) + (all->game.r.height / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (all->game.r.height / 2);
        if (drawEnd >= all->game.r.height)
            drawEnd = all->game.r.height - 1;

        int texNum = all->map.map[mapX][mapY] - 1;
        
		double wallX;
        if (side == 0)
            wallX = info->posY + perpWallDist * rayDirectionY;
        else
            wallX = info->posX + perpWallDist * rayDirectionX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)all->info.texWidth);
        if (side == 0 && rayDirectionX > 0)
            texX = all->info.texWidth - texX - 1;
        if (side == 1 && rayDirectionY < 0)
            texX = all->info.texWidth - texX - 1;

        double step = 1.0 * all->info.texHeight / lineHeight;
        double texPos = (drawStart - all->game.r.height / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y < drawEnd; y++)
        {
            int texY = (int)texPos & (all->info.texHeight - 1);
            texPos += step;
            int color = info->texture[texNum][all->info.texHeight * texY + texX];
            if (side == 1)
                color = (color >> 1) & 8355711;
            info->buf[y][x] = color;
        }
        x++;
    }
	return (0);
}

int key_press(int key, t_info *info, t_all *all)
{
    if (key == KEY_W)
    {
        if (!all->map.map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
            info->posX += info->dirX * info->moveSpeed;
        if (!all->map.map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
            info->posY += info->dirY * info->moveSpeed;
    }

    if (key == KEY_S)
    {
        if (!all->map.map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
            info->posX -= info->dirX * info->moveSpeed;
        if (!all->map.map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
            info->posY -= info->dirY * info->moveSpeed;
    }

    if (key == KEY_A)
    {
        double oldDirectionX = info->dirX;
        info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
        info->dirY = oldDirectionX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
        info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
    }

    if (key == KEY_D)
    {
        double oldDirectionX = info->dirX;
        info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
        info->dirY = oldDirectionX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
        info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
    }
    if (key == KEY_ESC)
        exit(0);
    return (0);
}

int main_loop(t_info *info, t_all *all)
{
    calculateAndSaveToMap(info, all);
    imageDraw(info, all);

    return (0);
}

void    load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
}

void    load_texture(t_all *all)
{
    load_image(&all->info, all->info.texture[0], "pics/wall_w.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[1], "pics/wall_e.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[2], "pics/wall_n.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[3], "pics/wall_s.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[4], "pics/wall_s.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[5], "pics/wall_s.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[6], "pics/wall_s.xpm", &all->info.img);
    load_image(&all->info, all->info.texture[7], "pics/wall_s.xpm", &all->info.img);
}

int ft_mlx_start(t_all *all)
{
    all->info.mlx = mlx_init();

	if (!(all->info.texture = (int **)malloc(sizeof(int *) * 8)))
        return (-1);
    for (int i = 0; i < 8; i++)
        if (!(all->info.texture[i] = (int *)malloc(sizeof(int) * (all->info.texHeight * all->info.texWidth))))
            return (-1);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < all->info.texHeight * all->info.texWidth; j++)
            all->info.texture[i][j] = 0;

	for (int i = 0; i < 8; i++)
        for (int j = 0; j < all->info.texHeight * all->info.texWidth; j++)
            all->info.texture[i][j] = 0;

    load_texture(all);

	all->info.win = mlx_new_window(all->info.mlx, all->game.r.width, all->game.r.height, "mlx");
	all->info.img.img = mlx_new_image(all->info.mlx, all->game.r.width, all->game.r.height);
	all->info.img.data = (int *)mlx_get_data_addr(all->info.img.img, &all->info.img.bpp, &all->info.img.size_l, &all->info.img.endian);

	mlx_loop_hook(all->info.mlx, &main_loop, &all->info);
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &key_press, &all->info);
    mlx_loop(all->info.mlx);
	return (0);
}
