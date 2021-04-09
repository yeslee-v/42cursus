/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:53:02 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 20:21:49 by yeslee           ###   ########.fr       */
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

void	ft_read_essential(char *line, t_all *all)
{
	if (all->game.cnt == 8)
		ft_read_map(line, all);
	else if (ft_isspace(line[0]))
		{
			printf("%s\n",line);
			ft_error_message(5);
		}
}

//char	**ft_parse_comma(char *line)
void	ft_parse_comma(char *line)
{
	char	**parsed;
	int		i;
	char	**temp;

	parsed = ft_calloc(4, sizeof(char *));
	temp = ft_split(line, ' ');
	parsed[0] = ft_strdup(temp[0]);
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	temp = ft_split(line + 1, ',');
	i = 0;
	while (i < 3)
	{
		parsed[i + 1] = ft_strtrim(temp[i], " ");
		i++;
	}
	printf("%s|%s|%s|%s|\n", parsed[0], parsed[1], parsed[2], parsed[3]); // 이 값 그대로 0, 1, 2를 r에 넣으면 된다
	//return (parsed);
}

void	ft_read_line(char *line, t_all *all)
{
	int		len;
	int		len_id;
	char	**res;

	ft_read_essential(line, all);
	res = ft_split(line, ' ');
	len = ft_double_strlen(res);
	len_id = ft_strlen(res[0]);
	if (ft_strnstr(res[0], "R", len_id) && (len_id == 1) && (len == 3))
		ft_put_size(res[1], res[2], &(all->game));
	else if (ft_strnstr(res[0], "NO", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.n), &(all->game));
	else if (ft_strnstr(res[0], "SO", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.s), &(all->game));
	else if (ft_strnstr(res[0], "WE", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.w), &(all->game));
	else if (ft_strnstr(res[0], "EA", len_id) && (len_id == 2) && (len == 2))
		ft_put_image(res[1], &(all->game.e), &(all->game));
	else if (ft_strnstr(res[0], "S", len_id) && (len_id == 1) && (len == 2))
		ft_put_image(res[1], &(all->game.sp), &(all->game));
	else
		//printf("line: %s\n", line);
		ft_parse_comma(line);
	ft_free_char(res);
}
