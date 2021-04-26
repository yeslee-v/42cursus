/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:20:54 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/26 20:09:39 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	t_lst	*lst;
	t_node	*header;
	t_node	*tail;

	if (ac == 1)
		ft_error_message();
	else if (ac == 2)
	{
		if (EOF)
			ft_ok();
	}
	i = 0;
	lst = ft_init_list();
	header = ft_get_node();
	tail = ft_get_node();
	header->next = tail;
	header = tail->prev;
	lst->head = ft_get_node();
	header->next = lst->head; // 값이 들어오는 인자는 header와 tail사이에 삽입 
	while (av[++i])
	{
		lst->head = ft_get_node();
		lst->head->data = ft_check_same(&av[i]);
		lst->head = lst->head->next;
		//free(lst->head);
		lst->num++;
	}
//	printf("tmp:%d\n", tmp->data);
//	ft_sa(tmp);
//	printf("sa:%d\n", lst->head->data);
	return (0);
}
