/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bgm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:21:56 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 14:28:59 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bgm_start(void)
{
	system("afplay ./bgm/rollin.mp3 -v 0.3 &");
}

void	ft_bgm_end(void)
{
	system("killall afplay");
}

int		ft_close(void)
{
	ft_bgm_end();
	exit(0);
	return (0);
}
