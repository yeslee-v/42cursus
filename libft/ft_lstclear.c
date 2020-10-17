/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:48:42 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/16 21:11:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!*lst || !del)
		return ;
	node = *lst;
	while (node->next)
	{
		temp = node->next;
		(*del)(node->content);
		free(node);
		node = temp;
	}
	free(node);
}
