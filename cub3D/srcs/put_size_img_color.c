/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/11 18:40:28 by yeslee           ###   ########.fr       */
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

void	ft_put_size(char *line, t_game *game)
{
	char **res;
	int	value;

	if (game->r.width || game->r.height)
		ft_error_message(5);
	res = ft_split(line, ' ');
	int i = -1;
	while (res[++i])
	{
		value = ft_check_atoi(res[i]);
		if (value)
		{
			if (!i)
				game->r.width = value;
			else if (i == 1)
				game->r.height = value;
			else if (i == 2)
				ft_error_message(1);
		}
	}
	game->cnt++;
	ft_free_char(res);
}

void	ft_put_image(char *line, char **img, t_game *game)
{
	char *tmp;

	if (*img)
		ft_error_message(5);
	tmp = ft_strnstr(line, ".xpm", ft_strlen(line));
	if ((!tmp) || (tmp[4]))
		ft_error_message(2);
	*img = ft_strdup(line);
	game->cnt++;
}

void	ft_put_color(char *line, char **rgb, t_game *game)
{
	printf("%s\n", line);
/*	char **res;
	char **idt;
	int		len;
	int		i;
	int rgb;

	res = ft_split(line, ',');
	len = ft_double_strlen(res);
	idt = ft_split(res[0], ' ');
	if (ft_strnstr(idt[0], "F", ft_strlen(idt[0])))
	{
		if (len == 3)
		{
			i = 0;
			while (res[i])
			{
				if (!i)
					rgb = ft_atoi(idt[1]);
				else
					rgb = ft_atoi(res[i]);
				if (((rgb >= 0) && (rgb <= 255)))
					game->f[i] = rgb;
				else
					ft_error_message(7);
				i++;
			}
		}
	}
	printf("%d|%d|%d\n", game->f[0], game->f[1], game->f[2]);*/
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
