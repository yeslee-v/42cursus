/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/30 21:55:39 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"


typedef	struct	s_list {
//	int		space;
//	char	plus;
	int		left;
	int		zero;
//	char	sharp;

	int		width;
	int		prec;	// precision

	char	type;	// cspdiuxX%

	int		len;	// length of va_arg(ap, int)
	//char	*value;	

	int		result;
	int		cnt;	// printf("%d\n", printf("%d\n", 123));
}				t_list;

char	ft_type(char c);
int		ft_len(int i);

void	ft_flag_d(t_list *lst);
const char	*ft_parsing(const char *str);

#endif
