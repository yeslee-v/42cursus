/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/12 17:02:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_atoi(char *s)
{
	int		i;
	int		ret;
	char	*trim_s;

	i = 0;
	trim_s = ft_strtrim(s, " ");
	while (trim_s[i])
	{
		if (!(ft_isdigit(trim_s[i])))
			ft_error_message(4);
		i++;
	}
	ret = ft_atoi(trim_s);
	free(trim_s);
	return (ret);
}

void	ft_put_size(char *line, t_game *game)
{
	int		i;
	int		value;
	char	**res;

	if (game->r.width || game->r.height)
		ft_error_message(5);
	res = ft_split(line, ' ');
	i = -1;
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

void	ft_put_color(char *line, int *rgb, t_game *game)
{
	char	**res;
	int		color;
	int		len;
	int		i;

	res = ft_split(line, ',');
	len = ft_double_strlen(res);
	if (len == 3)
	{
		i = -1;
		while (res[++i])
		{
			color = ft_check_atoi(res[i]);
			if (((color >= 0) && (color <= 255)))
				rgb[i] = color;
			else
				ft_error_message(7);
		}
	}
	else
		ft_error_message(7);
	ft_free_char(res);
	game->cnt++;
}
