/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:31:38 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/13 21:27:23 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_map(char *line, t_all *all)
{
	if (!(all->map.row))
		all->map.row = ft_strlen(line);
	else if (ft_strlen(line) > all->map.row)
		all->map.row = ft_strlen(line);
	all->map.col++;
	if ((all->map.row + all->map.col) < 5)
		ft_error_message(1);
	ft_check_valid_map(line, all);
}

void	ft_check_valid_map(char *line, t_all *all)
{
	int	i;
	int	j;
	int **original;
	//int	**visited;

	i = all->map.col;
	if (!(map = (char **)malloc(sizeof(char *) * i)))
		return ;
	// 예외처리
	// 형변환
	// 구조체 맵을 original에 옮겨서 확인
	map[i] = ft_strdup(line);
	if (ft_isspace(map[i]) || ft_strchr(map[i], '0') || ft_strchr(map[i], '1') ||
			ft_strchr(map[i], '2') || (ft_strchr(map[i], 'N') ||
				ft_strchr(map[i], 'S') || ft_strchr(map[i], 'W') ||
				ft_strchr(map[i], 'E')))
	{
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S') || ft_strchr(map[i], 'W') ||
				ft_strchr(map[i], 'E'))
		{
			all->map.exist_player += 1;
			if (all->map.exist_player > 1)
				ft_error_message(8);
		}
	}
	else
		printf("error\n");
	printf("map[%d]: %s\n", i, map[i]);
}
/*	i = 0;
	j = 0;
	while (j < ft_strlen(line))
	{
		if ((line[i] == '0') || (line[i] == '1') || (line[i] == '2') || 
				(line[i] == 'N') || (line[i] == 'S') || (line[i] == 'W') || (line[i] == 'E'))
		{
			printf("-------------------\n");
			printf("line: %s line[%d]: %c\n", line, i, line[i]);
			printf("exist: %d\n\n", all->map.exist_player);
			if ((line[i] == 'N') || (line[i] == 'S') || (line[i] == 'W') || (line[i] == 'E'))
			{
				all->map.exist_player += 1;
				if (all->map.exist_player > 1)
					ft_error_message(8);
			}
			i++;
		}
		//else
		//	ft_error_message(8);
		//	printf("who are you: %c\n", line[i]);
		//i++;
		j++;
	}*/
