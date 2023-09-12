/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cspd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:14:38 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/23 16:15:11 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_put_s("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_p(void *p)
{
	unsigned long long int	ullp1;

	ullp1 = (unsigned long long int)p;
	ft_put_s("0x");
	return (ft_put_x(ullp1, ullp1) + 2);
}

int	ft_put_d(int d)
{
	int		n;
	char	*str;

	str = ft_itoa(d);
	n = ft_put_s(str);
	free(str);
	return (n);
}
