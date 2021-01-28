/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:53:23 by yeslee            #+#    #+#             */
/*   Updated: 2021/01/29 01:28:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_istype(const char **str, t_lst *lst)
{
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == 'd' ||
		**str == 'i' || **str == 'u' || **str == 'x' || **str == 'X' ||
		**str == '%')
	{
		lst->type = **str;
		return (1);
	}
	return (0);
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

void	ft_check_len_pux(t_lst *lst)
{
	char	*len;

	len = "0";
	if (lst->type == 'u')
		len = ft_itoa_base(lst->res, 10, lst->type);
	else if (lst->type == 'p' || lst->type == 'x' || lst->type == 'X')
		len = ft_itoa_base(lst->res, 16, lst->type);
	lst->len = (lst->type == 'p') ? ft_strlen(len) + 2 : ft_strlen(len);
	free(len);
}

void	ft_check_len(t_lst *lst)
{
	int	i;

	i = 0;
	if (lst->type == 'c')
		lst->len = 1;
	else if (lst->type == 'd' || lst->type == 'i')
	{
		i = lst->res;
		lst->len = (i == -2147483648) ? 10 : ft_size(i);
	}
	else if (lst->type == 'p' || lst->type == 'u' || lst->type == 'x'
			|| lst->type == 'X')
		ft_check_len_pux(lst);
	else if (lst->type == '%')
		lst->len = 1;
	return ;
}

void	ft_check_result(const char **str, t_lst *lst, va_list *ap)
{
	if (ft_istype(str, lst))
	{
		if (**str == 'c')
			lst->res = va_arg(*ap, int);
		else if (**str == 's')
			lst->res_s = va_arg(*ap, char *);
		else if (**str == 'p')
			lst->res = va_arg(*ap, unsigned long long);
		else if (**str == 'd' || **str == 'i')
		{
			lst->res = va_arg(*ap, int);
			ft_negative_result(lst);
		}
		else if (**str == 'u')
			lst->res = va_arg(*ap, unsigned int);
		else if (**str == 'x')
			lst->res = va_arg(*ap, unsigned int);
		else if (**str == 'X')
			lst->res = va_arg(*ap, unsigned int);
		else if (**str == '%')
			lst->res_pct = '%';
		ft_check_len(lst);
	}
}
