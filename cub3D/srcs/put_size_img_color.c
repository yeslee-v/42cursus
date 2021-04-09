/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 11:49:09 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (game->r.width || game->r.height)
		ft_error_message(5);
	if ((ft_check_atoi(width)) && (ft_check_atoi(height)))
	{
		game->r.width = ft_check_atoi(width);
		game->r.height = ft_check_atoi(height);
		game->cnt++;
	}
	else
		ft_error_message(1);
}

void	ft_put_image(char *img, char **txtr_addr, t_game *game)
{
	char *tmp;

	if (*txtr_addr)
		ft_error_message(5);
	tmp = ft_strnstr(img, ".xpm", ft_strlen(img));
	if ((!*tmp) && (!tmp[4]))
		ft_error_message(2);
	*txtr_addr = ft_strdup(img);
	game->cnt++;
}

void	ft_put_color(char **color, int *color_arr, t_game *game)
{
	// int		i;
	// int		rgb;
	// char	**res;
	// int		len;

	color_arr = 0;
color = 0;
/*	res = ft_split(color, ',');
	len = ft_double_strlen(res);
	if (*color_arr)
		ft_error_message(5);
	if (len == 3)
	{
		i = 0;
		while (res[i])
		{
			rgb = ft_check_atoi(res[i]);
			printf("%d\n", rgb);
			if (((rgb >= 0) && (rgb <= 255)))
				color_arr[i] = rgb;
			else
				ft_error_message(7);
			i++;
		}
	}
	else
		ft_error_message(7);
	ft_free_char(res);*/
	game->cnt++;
}
