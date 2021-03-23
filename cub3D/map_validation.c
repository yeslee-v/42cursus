/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:29:35 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/23 01:00:15 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dfs_intro(t_all *all, int **dfs_map)
{
	int i;
	int j;

	i = 0;
	while (i < all->map.row)
	{
		j = 0;
		while (j < all->map.col)
		{
			if ((((!i) || (i == (all->map.row - 1))) || ((!j) ||
				(j == (all->map.col - 1)))) && (dfs_map[i][j] != 1))
				dfs_map[i][j] = 9;
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
			if ((dfs_map[i][j] == 9) &&
					((((i - 1) >= 0) && (dfs_map[i - 1][j] != 9)) ||
				(((i + 1) < all->map.row) && (dfs_map[i + 1][j] != 9)) ||
				(((j - 1) >= 0) && (dfs_map[i][j - 1] != 9)) ||
				(((j + 1) < all->map.col) && (dfs_map[i][j + 1] != 9))))
			{
				ft_dfs(all, dfs_map, i, j);
				if (dfs_map[all->map.player_row][all->map.player_col] == 9)
					ft_error_message(9);
			}
			j++;
		}
		i++;
	}
	ft_free_all_int(all, dfs_map);
}

void	ft_dfs(t_all *all, int **dfs_map, int i, int j)
{
	dfs_map[i][j] = 9;
	if (((i - 1) >= 0) && (dfs_map[i - 1][j] != 1) && (dfs_map[i - 1][j] != 9))
		ft_dfs(all, dfs_map, (i - 1), j);
	else if (((i + 1) < all->map.row) && (dfs_map[i + 1][j] != 1) &&
		(all->map.map[i + 1][j] != 9))
		ft_dfs(all, dfs_map, (i + 1), j);
	else if (((j - 1) >= 0) && (dfs_map[i][j - 1] != 1) &&
			(dfs_map[i][j - 1] != 9))
		ft_dfs(all, dfs_map, i, (j - 1));
	else if (((j + 1) < all->map.col) && (dfs_map[i][j + 1] != 1) &&
		(dfs_map[i][j + 1] != 9))
		ft_dfs(all, dfs_map, i, (j + 1));
	else
		return ;
}

void	ft_map_validation(t_all *all)
{
	int	i;
	int	j;
	int	**dfs_map;
	
	i = 0;
	dfs_map = calloc(sizeof(int *), all->map.row);
	if (!(dfs_map))
		return ;
	while (i < all->map.row)
	{
		dfs_map[i] = calloc(sizeof(int), all->map.col);
		if (!(dfs_map[i]))
			ft_free_all_int(all, dfs_map);
		j = 0;
		while (j < all->map.col)
		{
 			if (all->map.map[i][j] == '1')
 				dfs_map[i][j] = 1;
 			j++;
		}
		i++;
	}
	ft_dfs_intro(all, dfs_map);
}

void	ft_free_all_int(t_all *all, int **map)
{
	int i;

	if (map)
	{
		i = 0;
		while (i < all->map.row)
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
	map = 0;
	ft_error_message(10);
}
