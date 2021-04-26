/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_series.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:02:18 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/26 17:40:10 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list_a *lst_a, int n)
{
	lst_a	*tmp;

	tmp = lst_a;
	if (!(lst_a))
		return ;
	while (lst_a->next)
		lst_a = lst_a->next;
	lst_a->next = tmp;
	tmp->next = NULL;
}

/*void	ft_rb(t_list_b *lst_b, int n)
{

}*/
