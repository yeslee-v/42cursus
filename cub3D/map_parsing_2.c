/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/16 00:41:22 by yeslee           ###   ########.fr       */
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
	ft_input_map(line, all);
}

void	ft_ismap(char *line, t_all *all)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '0') || (line[i] == '1') || (line[i] == '2') ||
			(line[i] == 'N') || (line[i] == 'S') || (line[i] == 'W') ||
			(line[i] == 'E') || ft_isspace(line[i]))
		{
			if ((line[i] == 'N') || (line[i] == 'S') || (line[i] == 'W') ||
					(line[i] == 'E'))
			{
				all->map.cnt_exist += 1;
				if (all->map.cnt_exist > 1)
					ft_error_message(9);
			}
			i++;
		}
		else
			ft_error_message(7);
	}
}

void	ft_input_map(char *line, t_all *all)
{
	int	i;
	int	j;

	//printf("%d %d\n", all->map.col, all->map.row);
	//i = all->map.col - 1;
	i = 0;
	ft_ismap(line, all);
	if (!(all->map.map = malloc(sizeof(int *) * all->map.row)))
		return ;
	while (i < all->map.col)
	{
		all->map.map[i] = malloc(sizeof(int) * all->map.col);
		i++;
	}
//	if (!(all->map.map[i] = malloc(sizeof(int) * all->map.row)))
//		return ;
	j = 0;
	while (j < all->map.row)
	{
		if ((line[j] == 'N') || (line[j] == 'S') || (line[j] == 'W') ||
				(line[j] == 'E'))
		{
			all->map.player_row = j;
			all->map.player_col = i;
		}
		/*if (ft_isdigit(line[j]))
			all->map.map[i][j] = line[j] - 48;
		else
			all->map.map[i][j] = 0;*/
		j++;
	}
}

void	ft_dfs(t_all *all)
{
	int	i;
	int j;
	int	**copy_map;

	i = 0;
/*	printf("%d %d", all->map.col, all->map.row);
	if (!(copy_map = (int **)malloc(sizeof(int *) * all->map.col)))
		return ;
	if (!(copy_map = (int *)malloc(sizeof(int) * all->map.row)))
		return ;*/
	while (i < all->map.col)
	{
		j = 0;
		while (j < all->map.row)
		{
			//printf("%d %d\n", i, j);
			j++;
		}
		//printf("-----\n");
		i++;
	}
}
