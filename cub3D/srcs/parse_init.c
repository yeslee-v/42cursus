/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:41:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/08 21:32:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_struct_init(int ac, char **av, t_all *all)
{
	ft_bzero(&all->game.r, sizeof(t_window));
	ft_bzero(&all->game, sizeof(t_game));
	ft_bzero(&all->map, sizeof(t_map));
	ft_bzero(&all->save, sizeof(t_save));
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		all->save.pic = 1;
}
