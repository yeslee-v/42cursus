/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:07:50 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/14 18:18:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	node;

	node = *lst;
	while (node)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
