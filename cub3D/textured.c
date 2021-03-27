# include "cub3d.h"

/*
    texture를 입히기 위해서는 verLine() 함수를 이용해 수직선을 그리는 방식은 버려야 한다.
    대신, 픽셀을 하나하나 그려줄 것이다.
    우리가 사용할 방식을 쉽게 설명하면 2차원짜리 '버퍼'를 이용, 
    한번에 (변경된)화면을 출력하는 것이다.

    아래의 all->info.texWidth, all->info.texHeight는 텍스쳐의 텍셀 너비, 높이 값이다.

*/
//#define all->info.texWidth 64
//#define all->info.texHeight 64

/*int    all->map.map[all->map.row][all->map.col] =
{
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};*/

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
	info->buf = malloc(sizeof(int *) * all->game.r.width);
	if (!(info->buf))
		return (0);
	while (i < all->game.r.width)
	{
		info->buf[i] = malloc(sizeof(int) * all->game.r.height);
		if (!(info->buf[i]))
		{
			ft_free_all_int(info->buf, i);
			return (0);
		}
		i++;
	}
    // 화면 생성 후 게임 루프 시작.
    // while문은 전체 프레임을 그려내고 입력을 읽는 역할을 함.
	for (int x = 0; x < all->game.r.width; x++)
    {
        for (int y = 0; y < all->game.r.height; y++)
        {
            info->buf[y][x] = 0xFFFFFF; 
            info->buf[all->game.r.height - y - 1][x] = 0x000000;
            // buf[all->game.r.height - 1 ~ all->game.r.height - all->game.r.height][x] 를 칠해줌.
        }
    }

    int  x = 0;
    while (x < all->game.r.width)
    {
        // cameraX 는 for문의 x값이 카메라 평면 상에 있을 때의 x좌표.
        double cameraX = (2 * x / (double)(all->game.r.width)) - 1;
        // cameraPlaneX == 0; cameraPlaneY == 0.66; dirVecX = -1; dirVecY = 0;
        // 광선의 방향은 방향벡터 + 카메라평면 * 배수.
        double rayDirectionX = info->dirX + info->planeX * cameraX;
        double rayDirectionY = info->dirY + info->planeY * cameraX;

        /*
            DDAgorithm
        */
        // 현재 player가 위치한 맵 내 위치.(which box of the map)
        int mapX = (int)(info->posX);
        int mapY = (int)(info->posY);

        // 현재 위치에서 다음 x사이드 또는 y사이드까지의 거리.
        // 이를 이하 '첫 번째 x면 및 y면'이라고 부를 것.
        double sideDistX;
        double sideDistY;

        // 아래 두 변수가 왜 저렇게 구해지는지에 대해서는 ii2r github #6 참고. 
        // deltaDistX는 첫 번째 x면에서 그 다음 x면까지의 광선의 이동거리.
        // 이 경우 x는 1만큼 이동.
        // abs함수는 정수 절대값
        // fabs함수는 실수 절대값
        double deltaDistX = fabs(1 / rayDirectionX);
        // deltaDistY는 첫 번째 y면에서 그 다음 y면까지의 광선의 이동거리.
        // 이 경우 y는 1만큼 이동.
        double deltaDistY = fabs(1 / rayDirectionY);

        // 광선의 이동거리를 계산할 때 사용할 변수.
        double perpWallDist;

        // DDAgorithm은 반복문을 실행할 때마다 x, y방향으로 딱 한 칸씩 점프.
        // 광선의 방향에 따라 어느 방향으로 건너뛰는지 달라짐.
        // 그 정보는 stepX, Y에 +1, -1 둘 중 하나로 저장됨.
        int stepX;
        int stepY;

        /*
            hit은 벽과 부딪혔는지 판별하기 위한 변수임.
            부딪힌다는 것은 루프를 종료하기 위한 조건이 됨.
            만약 벽에 부딪혔는데 그게 x면에 부딪힌 거라면 side = 0임.
            y면에 부딪혔다면 1이 됨.
            한편 x면, y면은 어떤 칸의 경계가 되는 선을 의미함.
        */
        int hit = 0;
        int side;

        /*
            DDAgorithm을 시작하기 전에 
            stepX, Y 그리고 sideDistX, Y에 값을 넣어주는 부분이다.
            rayDirectionX가 음수라는 말은 player기준 왼각이라는 뜻이고,
            양수라는 말은 player기준 오른각이라는 뜻이다.
            sideDistX의 값은 rayDirectionX 값이 양수인 경우
            광선의 오른쪽으로 이동하다 처음 만나는 x면까지의 거리가 된다.
            sideDistY의 값은 rayDirectionY 값이 양수인 경우
            광선의 위쪽으로 이동하다 처음 만나는 y면까지의 거리가 된다.
            rayDirectionX가 양수일 경우 sideDistX는 
            mapX + 1에서 실제 위치 posX를 빼주고 deltaDistX를 곱한 결과다.
            반대의 경우 posX에서 mapX를 빼주고 deltaDistX를 곱한 결과다.
        */
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

        /*
            DDAgorithm 세팅을 완료했고, 이제 그것을 시작하는 부분.
            아래 while문은 `벽에 부딪힐 때까지` 매번 한 칸씩 광선 이동.
            반복할 때마다 x방향으로 한 칸 또는 y방향으로 한 칸 점프.
            만약 광선의 방향이 x축 방향과 완전히 일치한다면, x방향으로만 한 칸 점프하면 됨.
            광선이 점프할 때마다 <sideDistX, Y>에는 <deltaDistX, Y>가 더해지면서 업데이트됨.
        */
        while (hit == 0)
        {
            // 다음 map 박스로 이동하거나 x, y 방향 둘 중 하나로 이동한다.
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX; // stepX 는 1, -1 중 하나.
                side = 0; // x면에 부딪혔다면 side = 0
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY; // stepY는 1, -1 중 하나.
                side = 1; // y면에 부딪혔다면 side = 1
            }
            // ray가 벽을 만났는지 확인하는 작업
            if (all->map.map[mapX][mapY] > 0)
                hit = 1;
        }
        /*
            벽을 만나 DDAgorithm이 완료됨.
            이제 광선의 시작점에서 벽까지의 이동거리를 계산할 차례임.
            광선의 시작점에서 벽까지의 이동거리는 벽의 높이를 계산하는 데 쓰임.
            H------------ :wall
            | \          \: 실제거리
            |  \         |: 벽에서 camera plane까지의 거리.
            -----P------- :camera plane
            P를 기준으로 벽까지의 실제거리를 사용한다면 fisheye 부작용이 나타남.
            따라서 벽으로부터 cameraPlane까지의 거리를 사용해야.
            이에 대한 자세한 설명은 로데브 설명 참고.
            따라서 아래 if-else문은 fisheye (side)effect를 방지하는 코드.
            (1 - stepX) / 2는 stepX가 -1이면 1이되고 1이면 0이 된다.(-1 or 0)
            해당 연산은 mapX - posX가 < 0 일 때, 즉 벽 밖으로 갈 때
            길이에 1을 더해주기 위한 코드이다.
            수직거리를 계산하는 방법은 이렇다. 
            만약 광선이 처음으로 부딪힌 면이 x면이면 
                mapX - posX + (1 - stepX / 2)는
                광선이 x방향으로 몇 칸이나 갔는지를 나타낸다.(정수 아니어도 됨.)
                rayDirectionX로 나눠주는 이유는 구해진 값이 수직거리보다 크기 때문.
            y면에 처음 부딪혔을 때도 같은 원리로 동작.
            mapX - playerPostionX가 음수더라도 음수인 rayDirectionX로 나누기 때문에
            계산된 값은 항상 양수임.
        */
        if (side == 0)
            perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirectionX;
        else
            perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirectionY;

        // 스크린에 그릴 line의 높이를 계산.
        int lineHeight = (int)(all->game.r.height / perpWallDist);
        /*
            이제 계산한 거리를 가지고 화면에 그려야 하는 선의 높이를 구할 수 있다.
            벽을 더 높게 그리거나 낮게 그리고 싶으면 2 * lineHeight 같은 값을 넣을 수도 있다.
            위에서 구한 lineHeight로부터 우리는 선을 그릴 위치의 시작점과 끝점을 구해낼 수 있다.
            만약에 벽의 범위 (0 ~ all->game.r.height)를 벗어나는 경우 
            각각 0과 all->game.r.height - 1을 대입한다.
                +) drawStart와 End에 2로 나눈 값들을 더하는 이유는
                   all->game.r.height보다 drawEnd가 커지면 될까 안될까를 생각해보면 알 수 있다.
        */
        int drawStart = (-lineHeight / 2) + (all->game.r.height / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (all->game.r.height / 2);
        if (drawEnd >= all->game.r.height)
            drawEnd = all->game.r.height - 1;

        // texturing calculations
        // 1을 빼주는 이유는 0번째 텍스쳐도 0, 벽이 없어도 0이기 때문.
        // 1을 빼지 않는다면 어떻게 될까?
        // 아마 시작하자마자 뒷방향을 보고 앞으로 걸어나가려고 하면 
        // segmentation fault가 뜰 것이다.
        int texNum = all->map.map[mapX][mapY] - 1;
        // int textNum = all->map.map[mapX][mapY];

        // wallX의 값은 벽의 x면과 부딪힌 경우(side == 0)
        // 벽의 Y좌표가 된다.
        // wallX의 값은 텍스처의 x좌표에 대해서만 사용한다.
        double wallX;
        if (side == 0)
            wallX = info->posY + perpWallDist * rayDirectionY;
        else
            wallX = info->posX + perpWallDist * rayDirectionX;
        wallX -= floor(wallX);

        // texX는 texture의 x좌표를 나타낸다.
        // x coordinate on the texture
        int texX = (int)(wallX * (double)all->info.texWidth);
        if (side == 0 && rayDirectionX > 0)
            texX = all->info.texWidth - texX - 1;
        if (side == 1 && rayDirectionY < 0)
            texX = all->info.texWidth - texX - 1;

        /*
            texY를 지정하는 반복문.
            step은 스크린 픽셀당 texture 좌표를 얼마나 증가시켜줄 건지를 결정.
            buffer[y][x]에 넣을 color는 texture 배열에서 가져온다.
        */
        // How much to increase the texture coordinate perscreen pixel
        double step = 1.0 * all->info.texHeight / lineHeight;
        // Starting texture coordinate
        double texPos = (drawStart - all->game.r.height / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y < drawEnd; y++)
        {
            // Cast the texture coordinate to integer, and mask with (all->info.texHeight - 1) in case of overflow
            int texY = (int)texPos & (all->info.texHeight - 1);
            texPos += step;
            int color = info->texture[texNum][all->info.texHeight * texY + texX];
            // 광선이 벽의 y면에 부딪힌 경우(side == 1).
            // 조명표현을 위해 색상을 더 검게 만든다.
            // 이진수를 2로 나눔으로써 RGB값을 반감시킨다.
            // 시프트 연산을 하고 01111111 01111111 01111111(835711)을 & 연산하면
            // 어두운 값을 줄 수 있다는데 그냥 외워야 쓰것다.
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
	printf("loaded\n");
    // WS
    if (key == KEY_W)
    {
        if (!all->map.map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
            info->posX += info->dirX * info->moveSpeed;
        if (!all->map.map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
            info->posY += info->dirY * info->moveSpeed;
    }

    if (key == KEY_S)
    {
        /*  
            S키를 누르면 뒤로 이동한다.
            이때, 이동하고자 하는 위치는 맵 상에서 무조건 0이어야 한다.
            왜냐하면 맵 위에서 1~4가 의미하는 바는 통과할 수 없는 장애물이기 때문이다.
            만약 [2][2]맵이 있다고 할 때,
            위치의 오른쪽 위 지점에서 오른쪽 위를 바라보고 s키를 누르면
            왼쪽 아래 지점으로 이동해야 한다.
            이를 위해서는 x를 한칸 왼쪽으로 이동시키고,
            y를 한칸 아래로 이동시키면 된다.
            아래는 다음을 구체적으로 구현한 것이다.
        */
        if (!all->map.map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
            info->posX -= info->dirX * info->moveSpeed;
        if (!all->map.map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
            info->posY -= info->dirY * info->moveSpeed;
    }

   // AD
    if (key == KEY_A)
    {
        double oldDirectionX = info->dirX;
        info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
        info->dirY = oldDirectionX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
        info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
    }

    // https://github.com/ChoiKanghun/images/blob/master/1024_1.jpg?raw=true 
    // 위 이미지를 브라우저에 검색하자. 핵심이 되는 공식이다. 이 공식에 대한 자세한 설명은
    // https://github.com/minckim0/cub3d_lect 해당 깃 레포 내 pdf 62~66 페이지 참고.
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

    // warning 방지용.
    return (0);
}

/*
    https://42kchoi.tistory.com/229?category=886844
    위 링크에서 설명했듯이 mlx_png_file_to_image는 메모리 누수 이슈가 있기 때문에,
    mlx_xpm_file_to_image를 사용한다.
    참고로 여기서 path는 상대경로다.
*/
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
}

int ft_mlx_start(t_all *all)
{
    all->info.mlx = mlx_init();

	if (!(all->info.texture = (int **)malloc(sizeof(int *) * 4)))
        return (-1);
    for (int i = 0; i < 4; i++)
        if (!(all->info.texture[i] = (int *)malloc(sizeof(int) * (all->info.texHeight * all->info.texWidth))))
            return (-1);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < all->info.texHeight * all->info.texWidth; j++)
            all->info.texture[i][j] = 0;

    /*
        all->info.texture 변수는 다음과 같이 선언돼 있는데,
            int        texture[8][all->info.texHeight * all->info.texWidth];
        이것이 의미하는 바는 총 8가지 종류의 텍스쳐를 저장할 수 있고,
        그 크기가 all->info.texHeight * all->info.texWidth 라는 뜻이다.
    */
	for (int i = 0; i < 4; i++)
        for (int j = 0; j < all->info.texHeight * all->info.texWidth; j++)
            all->info.texture[i][j] = 0;

    load_texture(all);

    // textured에서 추가된 코드 세 줄.
	all->info.win = mlx_new_window(all->info.mlx, all->game.r.width, all->game.r.height, "mlx");
	all->info.img.img = mlx_new_image(all->info.mlx, all->game.r.width, all->game.r.height);
	all->info.img.data = (int *)mlx_get_data_addr(all->info.img.img, &all->info.img.bpp, &all->info.img.size_l, &all->info.img.endian);

    // 아래 코드들이 무슨 역할을 하는 지 궁금하다면 아래 링크에서 정리해둔 내용을 보자.
    // https://42kchoi.tistory.com/229
	mlx_loop_hook(all->info.mlx, &main_loop, &all->info);
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &key_press, &all->info);
    mlx_loop(all->info.mlx);
	return (0);
}
