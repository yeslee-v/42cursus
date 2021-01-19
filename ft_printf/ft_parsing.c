/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:38:00 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/19 17:31:02 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parsing(const char **str, t_lst *lst, va_list *ap)
{
	ft_check_flag(str, lst);
	ft_check_width(str, lst, ap);
	ft_check_prec(str, lst, ap);
	ft_check_result(str, lst, ap);
}
