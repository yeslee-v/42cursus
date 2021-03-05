/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:46:42 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/05 19:51:38 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error_message(int i)
{
	if (i == 1)
		perror("The number of arguments is invalid\n");
	else if (i == 2)
		perror("The contents of argument is invalid\n");
	else if (i == 3)
		printf("ERROR: %s\n", strerror(errno));
	exit(1);
}
