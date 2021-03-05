/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:30:21 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/05 20:52:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_error(int ac, char **av, int fd)
{
	if (!((ac > 1) && (ac < 4)))
		ft_error_message(1);
	if (!(ft_strnstr(av[1], ".cub", ft_strlen(av[1]))))
		ft_error_message(2);
	if ((fd = open(av[1], O_RDONLY) == -1))
		ft_error_message(3);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*buf;

	//mlx_init();
	//game_init();
	
	ft_check_error(ac, av, fd);
	
	//read(fd, buf, sizeof(buf));
	buf = NULL;
	while ((get_next_line(1, &buf)) > 0)
	{
		printf("%s\n", buf);
		free(buf);
		buf = NULL;
	}
	//close(fd);
	free(buf);
	return (0);
}
