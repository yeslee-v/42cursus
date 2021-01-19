/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/19 11:27:21 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_istype(const char **str)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
		**str == '%')
		return (**str);
	return ('0');
}

void	ft_parsing(const char **str, t_lst *lst, va_list *ap)
{
	ft_check_flag(str, lst);
	ft_check_width(str, lst, ap);
	ft_check_prec(str, lst, ap);
	ft_check_result(str, lst, ap);
	if (ft_istype(str))
		lst->type = **str;
	(*str)++;
}
