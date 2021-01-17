/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:53:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/17 22:02:43 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_negative_result(t_lst *lst)
{
	if (lst->res < 0)
	{
		lst->len = ft_size(lst->res) + 1;
		lst->sign = 1;
		lst->res *= -1;
	}
	else
		lst->len = ft_size(lst->res);
}

void	ft_check_result(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == 'c')
		lst->res = va_arg(*ap, int);
	else if (**str == 's')
		lst->res = va_arg(*ap, int);
	else if (**str == 'p')
		lst->res = va_arg(*ap, int);
	else if (**str == 'd' || **str == 'i')
		lst->res = va_arg(*ap, int);
	else if (**str == 'u')
		lst->res = va_arg(*ap, int);
	else if (**str == 'x')
		lst->res = va_arg(*ap, int);
	else if (**str == 'X')
		lst->res = va_arg(*ap, int);
	else if (**str == '%')
		lst->res = va_arg(*ap, int);
	ft_negative_result(lst);
}
