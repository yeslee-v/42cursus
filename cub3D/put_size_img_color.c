/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/10 17:49:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_size(char *width, char *height, t_game *game)
{
	game->r.width = ft_atoi(width);
	game->r.height = ft_atoi(height);
	game->cnt++;
}

void	ft_put_image(char *img, t_game *game)
{
	if (!(ft_strnstr(img, ".xpm", ft_strlen(img))))
		ft_error_message(2);
	if (ft_strnstr(img, "wall_n", ft_strlen(img)))
		game->n = img;
	else if (ft_strnstr(img, "wall_s", ft_strlen(img)))
		game->s = img;
	else if (ft_strnstr(img, "wall_w", ft_strlen(img)))
		game->w = img;
	else if (ft_strnstr(img, "wall_e", ft_strlen(img)))
		game->e = img;
	else if (ft_strnstr(img, "sprite", ft_strlen(img)))
		game->sp = img;
	game->cnt++;
}

void	ft_put_color(char *color, int *color_arr, int cnt)
{
	int		i;
	char	**res;

	res = ft_split(color, ',');
	i = 0;
	while (res[i])
	{
		color_arr[i] = ft_atoi(res[i]);
		i++;
	}
	cnt++;
}
