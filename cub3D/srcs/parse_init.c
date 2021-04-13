/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:41:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/13 17:56:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_save(int ac, char **av, t_all *all)
{
	if (ac > 4)
		ft_error_message(1);
	else if (av[2] && (ft_strlen(av[2]) != 6))
		ft_error_message(2);
	if ((ac == 3) && (!(ft_strncmp(av[2], "--save", ft_strlen(av[2])))))
		all->save.pic = 1;
	else if (ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		ft_error_message(2);
}

void	ft_struct_init(int ac, char **av, t_all *all)
{
	ft_bzero(&all->game.r, sizeof(t_window));
	ft_bzero(&all->game, sizeof(t_game));
	ft_bzero(&all->map, sizeof(t_map));
	ft_bzero(&all->save, sizeof(t_save));
	ft_check_save(ac, av, all);
}
