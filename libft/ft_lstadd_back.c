/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:21:40 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/15 21:34:36 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_next;

	if (!**lst || !*new)
		return ;
	*l_next = **lst->next;
	while (*l_next)
		*l_next = *l_next->next;
	l_next->next = new;
	new->next = NULL;
}
