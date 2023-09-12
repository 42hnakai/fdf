/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:47:27 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/23 16:29:01 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char a, va_list ap)
{
	va_list	ap1;

	va_copy(ap1, ap);
	if (a == 'c')
		return (ft_put_c((char)va_arg(ap, int)));
	else if (a == 's')
		return (ft_put_s(va_arg(ap, char *)));
	else if (a == 'p')
		return (ft_put_p(va_arg(ap, void *)));
	else if (a == 'd')
		return (ft_put_d(va_arg(ap, int)));
	else if (a == 'i')
		return (ft_put_i(va_arg(ap, int)));
	else if (a == 'u')
		return (ft_put_u(va_arg(ap, int)));
	else if (a == 'x')
		return (ft_put_x(va_arg(ap, unsigned int), va_arg(ap1, unsigned int)));
	else if (a == 'X')
		return (ft_put_upperx(va_arg(ap, unsigned int), va_arg(ap1,
					unsigned int)));
	else if (a == '%')
		return (ft_put_c('%'));
	va_end(ap1);
	return (-1);
}
