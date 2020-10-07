/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:07:09 by yeslee            #+#    #+#             */
/*   Updated: 2020/10/07 21:31:47 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);


int		ft_atoi(const char *str);
int		strncmp(const char *s1, const char *s2, size_t n);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(signed char c);
int		isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strlen(const char *c);

#endif
