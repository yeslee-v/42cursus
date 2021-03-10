/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:59:16 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/10 20:56:55 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_double_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_read_line(char *line, t_game *game)
{
	int		len;
	char	**res;

	if (game->cnt == 8)
		ft_read_map(line);
	else
		if (ft_isspace(line[0]))
			ft_error_message(6);
	res = ft_split(line, ' ');
	len = ft_double_strlen(res);
	if (ft_strnstr(res[0], "R", ft_strlen(res[0])) && len == 3)
		ft_put_size(res[1], res[2], game);
	else if (ft_strnstr(res[0], "NO", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], game);
	else if (ft_strnstr(res[0], "SO", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], game);
	else if (ft_strnstr(res[0], "WE", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], game);
	else if (ft_strnstr(res[0], "EA", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], game);
	else if (ft_strnstr(res[0], "S", ft_strlen(res[0])) && len == 2)
		ft_put_image(res[1], game);
	else if (ft_strnstr(res[0], "F", ft_strlen(res[0])) && len == 2)
		ft_put_color(res[1], game->f, game);
	else if (ft_strnstr(res[0], "C", ft_strlen(res[0])) && len == 2)
		ft_put_color(res[1], game->c, game);
}

void	ft_read_map(char *line)
{
	int		i;
	t_map	map;

	printf("Now: %s\n", line);
	i = 0;
	// printf("%c %zd\n", *line, ft_strlen(line));
	while (*line)
	{
		// printf("here: %c %zd\n", *line, ft_strlen(line));
		if (ft_strlen(line) > map.row)
			map.row = ft_strlen(line);
		else
			map.row = map.row;
		line++;
		i++;
	}
	map.col = i;
}
