/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:41:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/01 20:14:53 by yeslee           ###   ########.fr       */
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
	map->num_sp = 0;
	map->player_row = 0;
	map->player_col = 0;
	map->player = 0;
	map->map = 0;
	map->cnt_exist = 0;
}

void	ft_t_save_init_on(int ac, char **av, t_save *save)
{
	save->pic = 0;
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		save->pic = 1;
	if (save->pic)
		ft_save_bmp_intro(av);
}
