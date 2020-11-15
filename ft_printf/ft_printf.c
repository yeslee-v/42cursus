/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:15:41 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/15 15:28:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"
#include "./libft/libft.h"

int	ft_printf(const char *str, ...)
{
	t_list	lst;
	va_list	ap;

	va_start(ap, str);
	lst.result = va_arg(ap, int); // 
}
