/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:06:03 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/05 20:52:51 by yeslee           ###   ########.fr       */
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

typedef struct	s_game
{
	int	r;

	int	n;
	int	s;
	int	e;
	int	w;

	int	sp;

	int	f;
	int	c;
}				t_game;

void	ft_t_game_init(t_game *game);
void	ft_check_error(int ac, char **av, int fd);
void	ft_error_message(int i);
