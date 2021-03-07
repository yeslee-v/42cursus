/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/07 21:37:26 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_check_error(int ac, char **av)
{
	int	fd;

	if (!((ac > 1) && (ac < 4)))
		ft_error_message(1);
	if (!(ft_strnstr(av[1], ".cub", ft_strlen(av[1]))))
		ft_error_message(2);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error_message(3);
	return (fd);
}

char	**ft_space_on(char *line)
{
	char	**res;

	res = NULL;
	if (ft_strchr(line, ' '))
		res = ft_split(line, ' ');
	else if (ft_strchr(line, ','))
		res = ft_split(line, ',');
	else if (ft_strchr(line, 32))
		res = ft_split(line, '	');
	return (res);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	**res;

	ft_t_game_init();
	ft_t_save_init_on(ac, av);
	
	fd = ft_check_error(ac, av);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) > 2)
		{
			ft_read_line(line);
			//printf("%s\n", line);
			res = ft_space_on(line);
			while (*res)
			{
				//printf("%s|\n", *res);
				res++;
			}
			free(line);
		}
	}
	close(fd);
	//	free(line);
	return (0);
}
