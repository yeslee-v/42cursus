/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/13 15:48:07 by yeslee           ###   ########.fr       */
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
					ft_error_message(8);
			}
			else if (line[i] == '2')
				all->map.num_sp++;
			i++;
		}
		else
			ft_error_message(6);
	}
}

int		ft_input_origin(t_all *all, char **original, int *i, int *j)
{
	while (*i < all->map.row - 1)
	{
		original[*i] = malloc(sizeof(char) * (ft_strlen(all->map.map[*i]) + 1));
		if (!(original[*i]))
		{
			ft_free_all(original, *i);
			return (1);
		}
		*j = 0;
		while (*j < (int)ft_strlen(all->map.map[*i]))
		{
			original[*i][*j] = all->map.map[*i][*j];
			(*j)++;
		}
		original[*i][*j] = '\0';
		(*i)++;
	}
	return (0);
}

void	ft_input_map(char *line, t_all *all, int len)
{
	int		i;
	int		j;
	char	**original;

	i = 0;
	ft_ismap(line, all);
	original = (char **)malloc(sizeof(char *) * (all->map.row + 1));
	if (!(original))
		ft_error_message(10);
	if (ft_input_origin(all, original, &i, &j))
		ft_error_message(10);
	original[i + 1] = NULL;
	original[i] = malloc(len + 1);
	j = 0;
	while (j < len)
	{
		original[i][j] = line[j];
		j++;
	}
	original[i][j] = '\0';
	ft_free_char(all->map.map);
	all->map.map = original;
}

void	ft_read_map(char *line, t_all *all)
{
	int	len;

	len = ft_strlen(line);
	if (len > all->map.col)
		all->map.col = len;
	all->map.row++;
	ft_input_map(line, all, len);
}
