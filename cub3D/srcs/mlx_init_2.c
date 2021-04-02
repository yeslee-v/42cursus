/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:51:29 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/02 20:40:09 by yeslee           ###   ########.fr       */
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
	if (!(all->info.tex = (int **)malloc(sizeof(int *) * 4)))
        return ;
	while (i < 4)
	{
		if (!(all->info.tex[i] = (int *)malloc(sizeof(int) *
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
			all->info.tex[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_allocate_buf_for_texture(t_all *all)
{
	all->sp_buf.zBuffer = malloc(sizeof(double) * all->game.r.width);
	if (!(all->sp_buf.zBuffer))
		return ;
	all->sp_buf.spriteOrder = malloc(sizeof(double) * all->map.num_sp);
	if (!(all->sp_buf.spriteOrder))
		return ;
	all->sp_buf.spriteDistance = malloc(sizeof(double) * all->map.num_sp);
	if (!(all->sp_buf.spriteDistance))
		return ;
	all->sp_buf.sprite.texture = malloc(sizeof(int) * all->map.num_sp);
	if (!(all->sp_buf.sprite.texture))
		return ;
}
