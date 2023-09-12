/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:05:45 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/08 04:32:47 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>

// int main(void)
// {
// 	printf("ft_memcmp:%d\n", ft_memcmp("ABCDE", "ABC", 5));
// 	printf("memcmp   :%d\n", memcmp("ABCDE", "ABC", 5));
// 	printf("ft_memcmp:%d\n", ft_memcmp("world", 'd', 4));
// 	printf("memcmp   :%d\n", memcmp("world", 'd', 4));
// 	printf("ft_memcmp:%d\n", ft_memcmp("ABCDE", '\0', 10));
// 	printf("memcmp   :%d\n", memcmp("ABCDE", '\0', 10));
// 	return (0);
// }
