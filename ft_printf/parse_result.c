/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:53:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/23 01:48:27 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_istype(const char **str, t_lst *lst)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' || **str == '%')
		lst->type = **str;
	return ;
}

void	ft_negative_result(t_lst *lst)
{
	if (lst->res < 0)
	{
		lst->sign = 1;
		if (lst->width != 0)
			lst->width -= 1;
	}
	return ;
}

void	ft_check_len(t_lst *lst)
{
	if (lst->type == 'c' || lst->type == '%')
		lst->len = 1;
	else if (lst->type == 's')
		lst->len = (lst->res_s == NULL) ? 6 : ft_strlen(lst->res_s);
	else if (lst->type == 'd' || lst->type == 'i' || lst->type == 'u' || lst->type == 'p')
		lst->len = lst->res > 0 ? ft_size(lst->res) : ft_size((lst->res * -1));
	else if (lst->type == 'x' || lst->type == 'X')
		lst->len = ft_strlen(ft_itoa_base(lst->res, 16, lst->type));
	return ;
}

void	ft_check_result(const char **str, t_lst *lst, va_list *ap)
{
	if (**str == 'c')
		lst->res = va_arg(*ap, int);
	else if (**str == 's')
		lst->res_s = va_arg(*ap, char *);
	else if (**str == 'p')
		lst->res = va_arg(*ap, unsigned long long);
	else if (**str == 'd' || **str == 'i')
		lst->res = va_arg(*ap, int);
	else if (**str == 'u')
		lst->res = va_arg(*ap, unsigned int);
	else if (**str == 'x')
		lst->res = va_arg(*ap, unsigned int);
	else if (**str == 'X')
		lst->res = va_arg(*ap, unsigned int);
	else if (**str == '%')
		lst->res_pct = '%';
	ft_istype(str, lst);
	ft_check_len(lst);
	ft_negative_result(lst);
}
