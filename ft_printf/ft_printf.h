/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:15:55 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 21:37:32 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char a, va_list ap);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_p(void *p);
int	ft_put_d(int d);
int	ft_put_i(int i);
int	ft_put_u(int u);
int	ft_put_x(unsigned long long int x, unsigned long long int x1);
int	ft_put_upperx(unsigned long long int X, unsigned long long int X1);
int	ft_printf_count(unsigned long long int x);

#endif