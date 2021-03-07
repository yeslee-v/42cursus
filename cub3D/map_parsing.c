/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:59:16 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/07 21:05:20 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_read_line(char *line)
{
	int		i;
	t_game	game;

	i = 0;
	// if (game.cnt == 8)
	ft_read_map(line);
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		i++;
	if ((line[i] == 'R') && (line[i + 1] == ' '))
	{
		printf("R is done\n");

	}
	if ((line[i] == 'N') && (line[i + 1] == 'O') && (line[i + 2] == ' '))
	{
		printf("NO is done\n");

	}
	if ((line[i] == 'S') && (line[i + 1] == 'O') && (line[i + 2] == ' '))
	{

		printf("SO is done\n");
	}
	if ((line[i] == 'W') && (line[i + 1] == 'E') && (line[i + 2] == ' '))
	{
		printf("WE is done\n");

	}
	if ((line[i] == 'E') && (line[i + 1] == 'A') && (line[i + 2] == ' '))
	{
		printf("EA is done\n");

	}
	if ((line[i] == 'S') && (line[i + 1] == ' '))
	{
		printf("S is done\n");

	}
	if ((line[i] == 'F') && (line[i + 1] == ' '))
	{
		printf("F is done\n");

	}
	if ((line[i] == 'C') && (line[i + 1] == ' '))
	{
		printf("C is done\n");
	}
}

void	ft_read_map(char *line)
{
	int		i;
	t_map	map;

	i = 0;
		printf("%c %zd\n", *line, ft_strlen(line));
	while (*line)
	{
	//	printf("%c %zd\n", *line, ft_strlen(line));
		map.row = (ft_strlen(line) > map.row) ? ft_strlen(line) : map.row;
		line++;
		i++;
	}
	map.col = i;
}
