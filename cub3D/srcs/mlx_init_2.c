/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:51:29 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/31 21:59:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_allocate_texture(t_all *all)
{
	int i;
	int	j;

	i = 0;
	if (!(all->info.texture = (int **)malloc(sizeof(int *) * 4)))
        return ;
	while (i < 4)
	{
		if (!(all->info.texture[i] = (int *)malloc(sizeof(int) *
						(all->info.texHeight * all->info.texWidth))))
            return ;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
        while (j < (all->info.texHeight * all->info.texWidth))
		{
			all->info.texture[i][j] = 0;
			j++;
		}
		i++;
	}
}
