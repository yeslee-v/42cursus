/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_size_img_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:25:13 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/08 22:01:58 by yeslee           ###   ########.fr       */
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

	i++;
	res = ft_space_on(line);
	//	res = ft_space_on(*res);
	//printf("color_res: %s\n", res[i]);
	//	printf("color_i: %d\n", i);
	//	game->r.width = ft_atoi(res[i]);
	//	game->r.height = ft_atoi(res[i + 1]);
	//	printf("w:%d h:%d\n", ft_atoi(res[i]), ft_atoi(res[i + 1]));
	//	game->cnt++;
}
