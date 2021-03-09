/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/09 19:00:48 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_size(char *line, t_game *game, int i)
{
	char	**res;

	i++;
	res = ft_space_on(line);
	game->r.width = ft_atoi(res[i]);
	game->r.height = ft_atoi(res[i + 1]);
	//	game->cnt++;
	//	printf("cnt: %d\n", game->cnt);
}

void	ft_put_image(char *line, t_game *game, int i)
{
	char	**res;

	//printf("i: %d\n", i);
	res = ft_space_on(line);
	if (ft_strnstr(res[i], "NO", ft_strlen(res[i])))
		game->n = res[i + 1];
	else if (ft_strnstr(res[i], "SO", ft_strlen(res[i])))
		game->s = res[i + 1];
	else if (ft_strnstr(res[i], "WE", ft_strlen(res[i])))
		game->w = res[i + 1];
	else if (ft_strnstr(res[i], "EA", ft_strlen(res[i])))
		game->e = res[i + 1];
	else if (ft_strnstr(res[i], "EA", ft_strlen(res[i])))
		game->e = res[i + 1];
	else if (ft_strnstr(res[i], "S", ft_strlen(res[i])))
		game->sp = res[i + 1];
	//	game->cnt++;
}

void	ft_put_color(char *line, t_game *game, int i)
{
	char	**res;
	char	**color;

	i++;
	printf("line: %c\n", line[i]);
	printf("atoi: %d\n", ft_atoi(line));
/*	res = ft_space_on(line);
	color = ft_space_on(res[i]);
	while (game->f[i])
	{
		game->f[i] = ft_atoi(color[i]);
		i++;
	}
	i = 0;
	while (game->c[i - 1])
	{
		game->f[i] = ft_atoi(color[i]);
		i++;
	}
	printf("color_res: %d %d %d\n", game->f[0], game->f[1], game->f[2]);
	printf("color_res: %d %d %d\n", game->c[0], game->c[1], game->c[2]);*/
	//	printf("w:%d h:%d\n", ft_atoi(res[i]), ft_atoi(res[i + 1]));
	//	game->cnt++;
}
