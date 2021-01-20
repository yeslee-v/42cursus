/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:53:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/20 10:10:41 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_istype(const char **str, t_lst *lst)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
		**str == '%')
		lst->type = **str;
}

void	ft_negative_result(t_lst *lst)
{
	if (lst->res < 0)
	{
		lst->sign = 1;
		if (lst->width != 0)
			lst->width -= 1;
	}
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
	lst->len = lst->res > 0 ? ft_size(lst->res) : ft_size((lst->res * -1));
	ft_negative_result(lst);
	ft_istype(str, lst);
}
