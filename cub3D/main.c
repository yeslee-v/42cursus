/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/06 20:55:15 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_error(int ac, char **av)
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

char ft_space_on(char *buf)
{
	if (*buf == ' ' || (*buf >= 9 && *buf <= 13))
		return ('1');
	return (' ');
}

int	main(int ac, char **av)
{
	int		fd;
	char	res;
	char	*buf;
	char	**a;

	// mlx_init();
	ft_t_game_init();
	ft_t_save_init_on(ac, av);
	//ft_save_on(ac, av, &save);
	
	fd = ft_check_error(ac, av);
	
	while ((get_next_line(fd, &buf)) > 0)	// while 을 두 번 돌린다?
	{
		res = ft_space_on(buf);
		a = ft_split(buf, res);
		while (*a)
		{
			printf("%s|\n", *a);
			a++;
		}
		//printf("%s\n", buf);
		free(buf);
	}
	close(fd);
	free(buf);
	return (0);
}
