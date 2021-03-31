/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:36:44 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/30 17:20:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	all->info.posX = all->map.player_col;
	all->info.posY = all->map.player_row;
/*	all->info.dirX = -1.0;
	all->info.dirY = 0.0;
	all->info.planeX = 0.0;
	all->info.planeY = 0.66;*/
	all->info.moveSpeed = 0.5;
	all->info.rotSpeed = 0.5;
	all->info.texWidth = 64;
	all->info.texHeight = 64;
}

void	ft_t_save_init_on(int ac, char **av, t_save *save)
{
	save->pic = 0;
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		save->pic = 1;
}