/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/11 01:15:54 by yeslee           ###   ########.fr       */
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
			printf("digit:%d\n", s[i]);
			//ft_error_message(4);
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

void	ft_put_color(char *line, t_game *game)
{
	char **res;
	char **idt;
	int		len;
	int		i;
	int rgb;

	res = ft_split(line, ',');
	len = ft_double_strlen(res);
	idt = ft_split(res[0], ' ');
	if (ft_strnstr(idt[0], "F", ft_strlen(idt[0])))
	{
		printf("loaded %d\n", len);
		if (len == 3)
		{
			i = 0;
			while (res[i])
			{
				if (!i)
					rgb = ft_check_atoi(idt[1]);
				else
					rgb = ft_check_atoi(res[i]);
				if (((rgb >= 0) && (rgb <= 255)))
					game->f[i] = rgb;
				else
					ft_error_message(7);
				i++;
			}
		}
	}
	//printf("start:|%d|%d|%d|%d\n", ft_atoi(res[0] + 2), ft_atoi(res[1]), ft_atoi(res[2]), len);
	printf("%d|%d|%d\n", game->f[0], game->f[1], game->f[2]);
	//else if (ft_strnstr(idt[0], "C", ft_strlen(idt[0])))
	//	printf("start:|%d|%d|%d|%d\n", ft_atoi(res[0] + 2), ft_atoi(res[1]), ft_atoi(res[2]), len);
//	if (*color_arr)
//		ft_error_message(5);
/*	if (len == 3)
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
	game->cnt++;*/
}
