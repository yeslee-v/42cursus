/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:46:42 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 11:45:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_error_message(int error_num)
{
	if (error_num == 1)
		perror("The number of arguments is invalid\n");
	else if (error_num == 2)
		perror("The contents of argument is invalid\n");
	else if (error_num == 3)
		printf("ERROR: %s\n", strerror(errno));
	else if (error_num == 4)
		perror("It is not a number\n");
	else if (error_num == 5)
		perror("Parsing does not work\n");
	else if (error_num == 6)
		perror("The value is invalid\n");
	else if (error_num == 7)
		perror("The player dosen't exist\n");
	else if (error_num == 8)
		perror("The player exists only one\n");
	else if (error_num == 9)
		perror("The map is invalid\n");
	else if (error_num == 10)
		perror("Malloc error\n");
	else if (error_num == 11)
		perror("Can not open file\n");
	exit(0);
}
