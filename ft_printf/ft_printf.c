/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:05:39 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/23 16:39:33 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], ap);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	// long long int	a;
// 	// long long int	b;
// 	// void			*p;
// 	// void			*p1;

// 	// a = LONG_MAX;
// 	// b = LONG_MIN;
// 	// p = &a;
// 	// p1 = &b;
// 	ft_printf("%d\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
// 	// printf("%d\n", printf(" %p %p ", p, p1));
// 	// printf("%d\n", ft_printf(" NULL %s NULL ", s));
// 	// printf("%d\n", printf(" NULL %s NULL ", s));
// 	// printf("%d\n", ft_printf(" NULL %s NULL ", NULL), INT_MIN));
// 	// printf("%d\n", printf(" NULL %s NULL ", NULL), INT_MIN));
// 	return (0);
// }
