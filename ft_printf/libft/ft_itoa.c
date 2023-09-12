/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:03:03 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/11 09:47:33 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		n = n / 10;
		count++;
	}
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == INT_MIN)
	{
		str[--len] = 0 - (n % 10) + '0';
		n = n / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	str[--len] = n + '0';
	return (str);
}

// int main(void)
// {
// 	printf("%s", ft_itoa(42));
// 	return (0);
// }