/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:21:33 by yeslee            #+#    #+#             */
/*   Updated: 2021/06/24 04:02:30 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_cmd
{
	const char	*cmd[100];
	char *const	*av;
	char *const	*envp;

	int			fd[2];
}				t_cmd;

int				main(int ac, char **av, char **path);
void			ft_error_message(char *s);
void			ft_cmd_intro(const char *cmd_1, char **path, t_cmd *st_cmd);
void			ft_divid_path(const char *cmd_1, char **path, t_cmd *st_cmd);
void			ft_connect_i(int dest_fd);
void			ft_connect_o(int dest_fd);
void			ft_dup2(int fd, t_cmd *cmd);

#endif
