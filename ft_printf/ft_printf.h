/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:53 by yeslee            #+#    #+#             */
/*   Updated: 2020/11/18 17:54:46 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

//void	ft_normal_d(const char *str, ...);

typedef	struct	s_list {
	char	space;
	char	plus;
	char	left;
	char	zero;
	char	sharp;

	int		width;
	int		dot;
	int		prec;	// precision

	char	type;	// cspdiuxX%

	int		len;	// length of va_arg(ap, int)
	//char	*value;	

	int		result;
	int		cnt;	// printf("%d\n", printf("%d\n", 123));
}				t_list;

#endif
