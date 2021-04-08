/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:51:19 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/08 19:52:35 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_all(char **map, int max)
{
	int i;

	i = 0;
	if (map[i])
	{
		while (i < max)
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
	map = 0;
}

void	ft_free_all_int(int **map, int max)
{
	int i;

	if (map)
	{
		i = 0;
		while (i < max)
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
	map = 0;
}
