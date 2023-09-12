/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:35:25 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/28 15:38:43 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;

	i = 0;
	us = (unsigned char *)s;
	while (i < n)
	{
		if (us[i] == (unsigned char) c)
			return ((void *)(us + i));
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
// 	printf("ft_memchr:%p\n", ft_memchr("ABCDE", 'A', 3));
// 	printf("memchr   :%p\n", memchr("ABCDE", 'A', 3));
// 	printf("ft_memchr:%p\n", ft_memchr("world", 'd', 4));
// 	printf("memchr   :%p\n", memchr("world", 'd', 4));
// 	printf("ft_memchr:%p\n", ft_memchr("ABCDE", '\0', 10));
// 	printf("memchr   :%p\n", memchr("ABCDE", '\0', 10));
// 	return (0);
// }

// how to change 16 -> 10
// how to write? 1,null,2,3,4,5 -> "1\02345"