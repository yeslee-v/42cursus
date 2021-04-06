/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:51:29 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/06 14:21:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_allocate_buf(t_all *all)
{
	int i;

	i = 0;
	all->info.buf = malloc(sizeof(int *) * all->game.r.height);
	if (!(all->info.buf))
		return ;
	while (i < all->game.r.height)
	{
		all->info.buf[i] = malloc(sizeof(int) * all->game.r.width);
		if (!(all->info.buf[i]))
		{
			ft_free_all_int(all->info.buf, i);
			return ;
		}
		i++;
	}
}

void	ft_allocate_texture(t_all *all)
{
	int i;
	int	j;

	i = 0;
	if (!(all->info.tex = (int **)malloc(sizeof(int *) * 5)))
        return ;
	while (i < 5)
	{
		if (!(all->info.tex[i] = (int *)malloc(sizeof(int) *
						(all->info.texHeight * all->info.texWidth))))
            return ;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
        while (j < (all->info.texHeight * all->info.texWidth))
		{
			all->info.tex[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_allocate_sprite(t_all *all)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	all->sp.sprite = calloc(sizeof(t_sprite), all->map.num_sp);
	if (!(all->sp.sprite))
		return ;
	while (i < all->map.row)
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == '2')
			{
				all->sp.sprite[k].x = i + 0.5;
				all->sp.sprite[k].y = j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_allocate_buf_for_sprite(t_all *all)
{
	all->sp.zBuffer = malloc(sizeof(double) * all->game.r.width);
	if (!(all->sp.zBuffer))
		return ;
	all->sp.spriteOrder = malloc(sizeof(int) * all->map.num_sp);
	if (!(all->sp.spriteOrder))
		return ;
	all->sp.spriteDistance = malloc(sizeof(double) * all->map.num_sp);
	if (!(all->sp.spriteDistance))
		return ;
	ft_allocate_sprite(all);
}
