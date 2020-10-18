/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:47:25 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/18 22:00:01 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*node;

	size = ft_lstsize(lst);
	if (!(node = malloc(sizeof(t_list) * (size + 1))))
		return (0);
	while (lst->next)
	{
		(*f)(lst);
		ft_lstadd_back(lst);
}
