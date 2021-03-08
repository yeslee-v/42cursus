/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/08 21:42:44 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_space_on(char *line)
{
	char	**res;

	res = NULL;
	if (ft_strchr(line, ' '))
		res = ft_split(line, ' ');
	else if (ft_strchr(line, ','))
		res = ft_split(line, ',');
	else
		ft_error_message(5);
	return (res);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**res;
	t_all	all;

	ft_t_game_init(&(all.game));
	ft_t_save_init_on(ac, av, &(all.save));
	
	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			ft_read_line(line, &(all.game));
			free(line);
		}
	}
	close(fd);
	//	free(line);
	return (0);
}
