/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:40:26 by yeslee            #+#    #+#             */
/*   Updated: 2021/06/21 22:20:46 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main()
//int	main(int ac, char **av)
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd_1;
	int		fd_2;
	int		status;

	status = 10;
//	if (ac != 5)
//		perror("Error\n");
	pid_1 = fork();
	if (pid_1 == 0)
	{
		printf("before fork_mom: %d\n", getpid());
		pid_2 = fork();
		if (pid_2 == 0)
		{
			printf("first cmd >> child: %d\n", getpid());
			if ((fd_1 = open("./a.txt", O_WRONLY)) > 0)
				printf("open!!!!!!!\n\n");
			else
				printf("close!!!!!!!\n\n");
		}
		else
		{
			printf("second cmd >> mom: %d\n", getpid());
			wait(&status);
		}
	}
	else
	{
		printf("i'm grand process; %d\n", getpid());
		wait(&status);
	}
	printf("pid:wait = %d:%d\n", getpid(), status);
//	printf("parents: %d child: %d\n", getpid(), pid);
	return (0);
}
