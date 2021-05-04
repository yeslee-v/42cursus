/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:20 by yeslee            #+#    #+#             */
/*   Updated: 2021/05/04 23:56:15 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_lst *stack)
{
	int		i;
	int		j;
	t_node	*first;
	t_node	*second;

	i = stack->cnt + 1;
	first = stack->head;
	while (--i)
	{
		j = i;
		second = first->next;
		while (--j)
		{
			if (second->data < first->data)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}

void	ft_r_first(t_lst *a, t_lst *b, char *line)
{
	if ((line[1] == 'a') && (line[2] == '\0'))
		ft_ra(a);
	else if ((line[1] == 'b') && (line[2] == '\0'))
		ft_rb(b);
	else if ((line[1] == 'r') && (line[2] == '\0'))
		ft_rr(a, b);
	else if ((line[1] == 'r') && (line[2] == 'a') && (line[3] == '\0'))
		ft_rra(a);
	else if ((line[1] == 'r') && (line[2] == 'b') && (line[3] == '\0'))
		ft_rrb(b);
	else if ((line[1] == 'r') && (line[2] == 'r') && (line[3] == '\0'))
		ft_rrr(a, b);
}

void	ft_read(t_lst *a, t_lst *b)
{
	int		size;
	char	*line;

	while ((size = get_next_line(0, &line) > 0))
	{
		if ((line[0] == 's') && (line[1] == 'a') && (line[2] == '\0'))
			ft_sa(a);
		else if ((line[0] == 's') && (line[1] == 'b') && (line[2] == '\0'))
			ft_sb(b);
		else if ((line[0] == 's') && (line[1] == 's') && (line[2] == '\0'))
			ft_ss(a, b);
		else if ((line[0] == 'p') && (line[1] == 'a') && (line[2] == '\0'))
			ft_pa(a, b);
		else if ((line[0] == 'p') && (line[1] == 'b') && (line[2] == '\0'))
			ft_pb(b, a);
		else if (line[0] == 'r')
			ft_r_first(a, b, line);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (size == -1)
		ft_error_message();
	if (ft_is_sorted(a))
		ft_ok();
	else
		ft_ko();
}
