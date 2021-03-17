/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:29:35 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/17 12:20:24 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_dfs(t_all *all, int i, int j)
{
	if ((((!i) || (i == (all->map.row - 1))) || ((!j) || (j == (all->map.col - 1)))) && (!(all->map.map[i][j])))
		return (9);
	return (all->map.map[i][j]);
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
			all->map.map[i][j] = ft_dfs(all, i, j);
			//printf("%d", all->map.map[i][j]);
			j++;
		}
	//	printf("\n");
		i++;
	}
	//printf("\n");
	i = 0;
	while (i < all->map.row)
	{
		j = 0;
		while (j < all->map.col)
		{
			if (all->map.map[i][j] == 9)
			{
				if (all->map.map[i - 1][j] != 1)
				{
					i--;
					
				}
				else if (all->map.map[i + 1][j] != 1)
				{
					i++;
				}
				else if (all->map.map[i][j - 1] != 1)
				{
					j--;
				}
				else if	(all->map.map[i][j + 1] != 1)
					j++;
			}
				
		}
	}
}
