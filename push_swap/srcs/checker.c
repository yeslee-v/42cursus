/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/04 18:29:41 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read(t_lst *a, t_lst *b)
{
	char *line;

	while ((get_next_line(0, &line) > 0))
	{
		if ((line[0] == 's') && (line[1] == 'a') && (line[2] == '\0'))
			ft_sa(a); // segv
		else if ((line[0] == 's') && (line[1] == 'b') && (line[2] == '\0'))
			ft_sb(b);
		else if ((line[0] == 's') && (line[1] == 's') && (line[2] == '\0'))
			ft_ss(a, b);
		else if ((line[0] == 'p') && (line[1] == 'a') && (line[2] == '\0'))
			ft_pa(a, b);
		else if ((line[0] == 'p') && (line[1] == 'b') && (line[2] == '\0'))
			ft_pb(b, a);
		else if ((line[0] == 'r') && (line[1] == 'a') && (line[2] == '\0'))
			ft_ra(a);
		else if ((line[0] == 'r') && (line[1] == 'b') && (line[2] == '\0'))
			ft_rb(b);
		else if ((line[0] == 'r') && (line[1] == 'r') && (line[2] == '\0'))
			ft_rr(a, b);
		else if ((line[0] == 'r') && (line[1] == 'r') && (line[2] == 'a') && (line[3] == '\0'))
			ft_rra(a);
		else if ((line[0] == 'r') && (line[1] == 'r') && (line[2] == 'b') && (line[3] == '\0'))
			ft_rrb(b);
		else if ((line[0] == 'r') && (line[1] == 'r') && (line[2] == 'r') && (line[3] == '\0'))
			ft_rrr(a, b);
		write(1, &line, ft_strlen(line));
		free(line);
	}
}
