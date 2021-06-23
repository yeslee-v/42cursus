/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:40:26 by yeslee            #+#    #+#             */
/*   Updated: 2021/06/24 04:10:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	ft_execve(t_cmd *st_cmd)
{
	int		i;

	i = ft_double_len(st_cmd->cmd);
	while (--i >= 0)
		execve(st_cmd->cmd[i], st_cmd->av, st_cmd->envp);
	ft_error_message("execve error");
}

static void	ft_pid_zero(char **av, char **path, t_cmd *cmd)
{
	int		pid;
	int		status;

	pipe(cmd->fd);
	pid = fork();
	if (pid == 0)
	{
		ft_divid_path(av[2], path, cmd);
		ft_connect_i(0);
		ft_dup2(1, cmd);
		ft_execve(cmd);
	}
	else
	{
		wait(&status);
		ft_divid_path(av[3], path, cmd);
		ft_connect_o(1);
		ft_dup2(0, cmd);
		ft_execve(cmd);
	}
}

int			main(int ac, char **av, char **path)
{
	pid_t	pid;
	t_cmd	cmd;
	int		status;

	if (ac != 5)
		ft_error_message("The arguments are invalid");
	pid = fork();
	if (pid == 0)
		ft_pid_zero(av, path, &cmd);
	else
		wait(&status);
	return (0);
}
