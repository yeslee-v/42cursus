/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/21 23:22:54 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "include/libft/libft.h"

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
			if ((line[i] == 'N') || (line[i] == 'S') || (line[i] == 'W') || (line[i] == 'E'))
			{
				all->map.cnt_exist += 1;
				if (all->map.cnt_exist > 1)
					ft_error_message(8);
			}
			i++;
		}
		else
			ft_error_message(6);
	}
}

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
		if (!(original[i]))
			ft_free_all(all, original);
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
		if (!(ft_isspace(line[j])))
		{
			if (ft_isdigit(line[j]))
			{
				original[i][j] = line[j] - 48;
			}
			else if ((line[j] == 'N') || (line[j] == 'S') || (line[j] == 'W') ||
				(line[j] == 'E'))
			{
				all->map.player_row = i;
				all->map.player_col = j;
				original[i][j] = 0;
			}
		}
		else
		{
			original[i][j] = 0;
		}
		j++;
	}
	all->map.map = original;
	original = 0;
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
	ft_input_map(line, all, len);
}

void	ft_free_all(t_all *all, int **original)
{
	int	i;

	i = 0;
	while (i < all->map.row)
	{
		free(original[i]);
		i++;
	}
	free(original);
}
