/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 02:16:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 02:27:00 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bubble_sort(int *buf1, double *buf2, int num)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num - 1)
		{
			if (buf2[j + 1] > buf2[j])
			{
				temp = buf2[j];
				buf2[j] = buf2[j + 1];
				buf2[j + 1] = temp;
				temp = buf1[j];
				buf1[j] = buf1[j + 1];
				buf1[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_sprite_init(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->map.num_sp)
	{
		all->sp.sp_order[i] = i;
		all->sp.sp_dist[i] = ((all->info.posX - all->sp.sprite[i].x) *
									(all->info.posX - all->sp.sprite[i].x) +
								(all->info.posY - all->sp.sprite[i].y) *
									(all->info.posY - all->sp.sprite[i].y));
		i++;
	}
	ft_bubble_sort(all->sp.sp_order, all->sp.sp_dist, all->map.num_sp);
}
