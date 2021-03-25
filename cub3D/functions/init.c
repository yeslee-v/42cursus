/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:36:44 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/24 18:04:40 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	ft_t_game_init(t_game *game)
{
	game->n = 0;
	game->s = "0";
	game->e = "0";
	game->w = "0";
	game->sp = "0";
	game->cnt = 0;
}

void	ft_t_window_init(t_window *window)
{
	window->width = 0;
	window->height = 0;
}

void	ft_t_map_init(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->player_row = 0;
	map->player_col = 0;
	map->map = 0;
	map->cnt_exist = 0;
}

void	ft_t_info_init(t_all *all)
{
	int i;
	int j;

	all->info.posX = 12;
	all->info.posY = 5;
	all->info.dirX = -1;
	all->info.dirY = 0;
	all->info.planeX = 0;
	all->info.planeY = 0.66;
	all->info.moveSpeed = 0.05;
	all->info.rotSpeed = 0.05;

/*	i = 0;
	while (i < all->game.r.height)
	{
		j = 0;
		while (j < all->game.r.width)
		{
			all->info.buf[i][j] = 0;
			j++;
		}
		i++;
	}
	all->info.texture = malloc(sizeof(int *) * 5);
	if (!(all->info.texture))
		return ;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < texHeight * texWidth)
		{
			all->info.texture[i][j] = 0;
			j++;
		}
		i++;
	}*/
}

void	ft_t_save_init_on(int ac, char **av, t_save *save)
{
	save->pic = 0;
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		save->pic = 1;
}
