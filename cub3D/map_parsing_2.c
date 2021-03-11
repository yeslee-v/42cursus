/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/11 22:09:51 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_map(char *line, t_all *all)
{
	if (!(all->map.row))
		all->map.row = ft_strlen(line);
	else if (ft_strlen(line) > all->map.row)
		all->map.row = ft_strlen(line);
	all->map.col++;
	if ((all->map.row + all->map.col) < 5)
		ft_error_message(1);
}
