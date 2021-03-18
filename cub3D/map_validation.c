/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:29:35 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/18 11:36:22 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dfs(t_all *all, int i, int j)
{
	while (i < all->map.row)
	{
		while (j < all->map.col)
		{
			if (all->map.map[i][j] == 9)
			{
				if	(((i - 1) >= 0) && !(all->map.map[i - 1][j]))
				{
					all->map.map[i - 1][j] = 9;
					ft_dfs(all, (i - 1), j);
				}
				if (((i + 1) < all->map.row) && !(all->map.map[i + 1][j]))
				{
					all->map.map[i + 1][j] = 9;
					ft_dfs(all, (i + 1), j);
				}
				if (((j - 1) >= 0) && !(all->map.map[i][j - 1]))
				{
					all->map.map[i][j - 1] = 9;
					ft_dfs(all, i, (j - 1));
				}
				if (((j + 1) < all->map.col) && !(all->map.map[i][j + 1]))
				{
					all->map.map[i][j + 1] = 9;
					ft_dfs(all, i, (j + 1));
				}
			}
			else
				return ;
			j++;
		}
		i++;
	}
}

void	ft_map_validation(t_all *all)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < all->map.row)
	{
		j = 0;
		while (j < all->map.col)
		{
			if ((((!i) || (i == (all->map.row - 1))) || ((!j) || (j == (all->map.col - 1)))) && (!(all->map.map[i][j])))
				all->map.map[i][j] = 9;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < all->map.row)
	{
		j = 0;
		while (j < all->map.col)
		{
			if ((all->map.map[i][j] == 9) &&
					(((i - 1) >= 0) && !(all->map.map[i - 1][j])) ||
					(((i + 1) < all->map.row) && !(all->map.map[i + 1][j])) ||
						(((j - 1) >= 0) && !(all->map.map[i][j - 1])) ||
						(((j + 1) < all->map.col) && !(all->map.map[i][j + 1])))
			{
				ft_dfs(all, i, j);
				if (all->map.map[i][j] == 9)
					ft_error_message(10);
			}
		j++;
		}
	i++;
	}
}
