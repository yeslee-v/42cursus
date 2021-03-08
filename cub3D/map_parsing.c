/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:59:16 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/08 22:01:33 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_read_line(char *line, t_game *game)
{
	int		i;

	i = 0;
	//printf("game.cnt: %d\n", game.cnt);
	// if (game.cnt == 8)
	//	ft_read_map(line);
	if (ft_isspace(line[i]))
		ft_error_message(6);
	else
	{
		if ((line[i] == 'R') && ft_isspace(line[i + 1]))
			ft_put_size(line, game, i);
		if ((line[i] == 'N') && (line[i + 1] == 'O') && ft_isspace(line[i + 2]))
			ft_put_image(line, game, i);
		else if ((line[i] == 'S') && (line[i + 1] == 'O') &&
				ft_isspace(line[i + 2]))
			ft_put_image(line, game, i);
		else if ((line[i] == 'W') && (line[i + 1] == 'E') &&
				ft_isspace(line[i + 2]))
			ft_put_image(line, game, i);
		else if ((line[i] == 'E') && (line[i + 1] == 'A') &&
				ft_isspace(line[i + 2]))
			ft_put_image(line, game, i);
		else if ((line[i] == 'S') && ft_isspace(line[i + 1]))
			ft_put_image(line, game, i);
		else if ((line[i] == 'F') && ft_isspace(line[i + 1]))
			ft_put_color(line, game, i);
		else if ((line[i] == 'C') && ft_isspace(line[i + 1]))
			ft_put_color(line, game, i);
	}
	//game.cnt++;
}

void	ft_read_map(char *line, t_map *map)
{
	int		i;

	i = 0;
	// printf("%c %zd\n", *line, ft_strlen(line));
	while (*line)
	{
		// printf("here: %c %zd\n", *line, ft_strlen(line));
		map->row = (ft_strlen(line) > map->row) ? ft_strlen(line) : map->row;
		line++;
		i++;
	}
	map->col = i;
}
