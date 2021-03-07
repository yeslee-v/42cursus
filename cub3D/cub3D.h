/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:06:03 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/07 20:33:36 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "./include/libft/libft.h"
#include "./include/get_next_line/get_next_line.h"

typedef struct	s_window
{
	int	width;
	int	height;
}				t_window;

typedef struct	s_game
{
	t_window	r;

	int	n;
	int	s;
	int	e;
	int	w;

	int	sp;

	int	f;
	int	c;

	int	cnt;
}				t_game;

typedef struct	s_map
{
	int	row;
	int	col;
}				t_map;

typedef struct	s_save
{
	int	pic;
}				t_save;

int		main(int ac, char **av);

void	ft_t_game_init();
void	ft_t_save_init_on(int ac, char **av);

int		ft_check_error(int ac, char **av);
void	ft_error_message(int i);

void	ft_read_line(char *line);
void	ft_read_map(char *line);
