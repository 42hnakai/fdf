/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:05:27 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/29 20:28:35 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return (i);
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
			i++;
		else if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
			return (i + 1);
		else
			return (-1);
	}
	return (-1);
}

int	ft_atoi(const char *str)
{
	long	num;
	size_t	i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	if (ft_check(str) == -1)
		return (0);
	i = ft_check(str);
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (ft_isdigit(str[i + 1]))
	{
		num = (num + sign * (str[i++] - '0')) * 10;
		if (((num <= LONG_MIN / 10) && (str[i] - '0' > LONG_MAX % 10))
			|| (LONG_MIN < num && num < LONG_MIN / 10 && str[i + 1] != '\0'))
			return ((int)(LONG_MIN));
		if (((num / 10 >= LONG_MAX / 10) && (str[i] - '0' > LONG_MAX % 10))
			|| (LONG_MAX / 10 < num && num < LONG_MAX && str[i + 1] != '\0'))
			return ((int)(LONG_MAX));
	}
	num = num + sign * (str[i] - '0');
	return ((int)num);
}

// int main(void)
// {
// 	printf("%d\n",ft_check("123"));
// 	printf("ft_atoi:%d\n", ft_atoi(" --1"));
// 	printf("atoi   :%d\n", atoi(" --1"));
// 	printf("ft_atoi:%d\n", ft_atoi("+1"));
// 	printf("atoi   :%d\n", atoi("+1"));
// 	printf("ft_atoi:%d\n", ft_atoi("123"));
// 	printf("atoi   :%d\n", atoi("123"));
// 	printf("ft_atoi:%d\n", ft_atoi("+42lyon"));
// 	printf("atoi   :%d\n", atoi("+42lyon"));
// 	printf("ft_atoi:%d\n", ft_atoi("   +12345"));
// 	printf("atoi   :%d\n", atoi("   +12345"));
// 	printf("ft_atoi:%d\n", ft_atoi("- 12345"));
// 	printf("atoi   :%d\n", atoi("- 12345"));
// 	printf("ft_atoi:%d\n", ft_atoi("-2147483648"));
// 	printf("atoi   :%d\n", atoi("-2147483648"));
// 	printf("ft_atoi:%d\n", ft_atoi("9223372036854775808"));	 // LONG_MAX+1
// 	printf("atoi   :%d\n", atoi("9223372036854775808"));	 // LONG_MAX+1
// 	printf("ft_atoi:%d\n", ft_atoi("-9223372036854775809")); // LONG_MIN-1
// 	printf("atoi   :%d\n", atoi("-9223372036854775809"));	 // LONG_MIN-1
// 	printf("ft_atoi:%d\n", ft_atoi("18446744073709551616")); // ULONG_MAX+1
// 	printf("atoi   :%d\n", atoi("18446744073709551616"));	 // ULONG_MAX+1
// 	printf("ft_atoi:%d\n", ft_atoi("9223372036854775806"));	 // LONG_MAX-1
// 	printf("atoi   :%d\n", atoi("9223372036854775806"));	 // LONG_MAX-1
// 	printf("ft_atoi:%d\n", ft_atoi("-9223372036854775807")); // LONG_MIN+1
// 	printf("atoi   :%d\n", atoi("-9223372036854775807"));	 // LONG_MIN+1
// 	return (0);
// }
