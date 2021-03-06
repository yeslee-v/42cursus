/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:36:44 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/06 20:51:27 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_t_game_init()
{
	t_game	game;

	game.r = 0;
	game.n = 0;
	game.s = 0;
	game.e = 0;
	game.w = 0;
	game.sp = 0;
	game.f = 0;
	game.c = 0;
}

void	ft_t_save_init_on(int ac, char **av)
{
	t_save	save;

	save.pic = 0;
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		save.pic = 1;
}

/*void	ft_save_on(int ac, char **av, t_save *save)
{
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		save->pic = 1;
}*/
