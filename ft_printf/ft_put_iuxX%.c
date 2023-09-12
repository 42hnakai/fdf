/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_iuxX%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:15:53 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:05:43 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_i(int i)
{
	int		n;
	char	*str;

	str = ft_itoa(i);
	n = ft_put_s(str);
	free(str);
	return (n);
}

int	ft_put_u(int u)
{
	long long int	uu;

	uu = (long long int)u;
	if (uu > INT_MAX)
		return (ft_put_d(uu / 10) + ft_put_d(uu % 10));
	else if (uu >= 0)
		return (ft_put_d(uu));
	else
	{
		uu = UINT_MAX + u + 1;
		return (ft_put_d(uu / 10) + ft_put_d(uu % 10));
	}
}

int	ft_put_x(unsigned long long int x, unsigned long long int x1)
{
	if (x / 16 > 0)
		ft_put_x(x / 16, x1);
	if (x % 16 < 10)
		ft_put_c(x % 16 + '0');
	else
		ft_put_c((x % 16) % 10 + 'a');
	return (ft_printf_count(x1));
}

int	ft_put_upperx(unsigned long long int X, unsigned long long int X1)
{
	if (X / 16 > 0)
		ft_put_upperx(X / 16, X1);
	if (X % 16 < 10)
		ft_put_c(X % 16 + '0');
	else
		ft_put_c((X % 16) % 10 + 'A');
	return (ft_printf_count(X1));
}
