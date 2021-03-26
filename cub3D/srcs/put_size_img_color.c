/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/26 13:27:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_atoi(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			ft_error_message(4);
		i++;
	}
	return (ft_atoi(s));
}

void	ft_put_size(char *width, char *height, t_game *game)
{
	if ((ft_check_atoi(width)) && (ft_check_atoi(height)))
	{
		game->r.width = ft_check_atoi(width);
		game->r.height = ft_check_atoi(height);
		game->cnt++;
	}
	else
		ft_error_message(1);
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

void	ft_put_color(char *color, int *color_arr, t_game *game)
{
	int		i;
	int		rgb;
	char	**res;
	int		len;

	res = ft_split(color, ',');
	len = ft_double_strlen(res);
	if (len == 3)
	{
		i = 0;
		while (res[i])
		{
			rgb = ft_check_atoi(res[i]);
			if (((rgb >= 0) && (rgb <= 255)))
				color_arr[i] = rgb;
			else
				ft_error_message(7);
			i++;
		}
	}
	else
		ft_error_message(7);
	game->cnt++;
}
