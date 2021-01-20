/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:46:51 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/21 00:51:06 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_print_percent(t_lst *lst)
{
	if (!(lst->len % 2))
		return ;
	//ft_print_d_i(lst);
	printf("%c", lst->res_pct);
}
