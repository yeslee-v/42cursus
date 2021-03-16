/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/16 20:40:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

//void	ft_set_player_

void	ft_input_map(char *line, t_all *all, int len)
{
	int	i;
	int	j;
	int	**original;

	i = 0;
	ft_ismap(line, all);
	if (!(original = malloc(sizeof(int *) * all->map.row)))
		return ;
	while (i < all->map.row)
	{
		original[i] = malloc(sizeof(int) * all->map.col);
		i++;
	}
	i = 0;
	while (i < all->map.row - 1)
	{
		j = 0;
		while (j < len)
		{
			original[i][j] = all->map.map[i][j];
			j++;
		}
		if (j != all->map.col)
		{
			while (j < all->map.col)
			{
				original[i][j] = 0;
				j++;
			}
		}
		i++;
	}
	j = 0;
	while (j < all->map.col)
	{
		if ((line[j] == 'N') || (line[j] == 'S') || (line[j] == 'W') ||
				(line[j] == 'E'))
		{
			all->map.player_row = i;
			all->map.player_col = j;
		}
		if (ft_isdigit(line[j]))
			original[i][j] = line[j] - 48;
		else
			original[i][j] = 0;
		j++;
	}
	/*	i = 0;
		if (all->map.map)
		{
			while (i < all->map.row)
			{
				free(all->map.map[i]);
				i++;
			}
			free(all->map.map);
		}*/
	all->map.map = original;
}

void	ft_read_map(char *line, t_all *all)
{
	int	len;

	len = all->map.col;
	if (!(all->map.col))
		all->map.col = ft_strlen(line);
	else if (ft_strlen(line) > all->map.col)
		all->map.col = ft_strlen(line);
	all->map.row++;
	//	if ((all->map.row + all->map.col) < 5) 지울지 안지울지 아직 미지
	//		ft_error_message(1);
	ft_input_map(line, all, len);
}
