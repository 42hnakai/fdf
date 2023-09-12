/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:47:41 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/10 23:47:41 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;

	if (dst == src || len == 0)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (usrc < udst)
	{
		while (len > 0)
		{
			udst[len - 1] = usrc[len - 1];
			len--;
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}

// #include <string.h>
// #include <stddef.h>
// int main(void)
// {
// 	char buf1[] = "ABCDEF";
// 	char buf2[] = "12345678";
// 	size_t len = 8;
// 	printf("ft_memmove:%s\n", (char *)ft_memmove(buf1, buf2, len));
// 	printf("memmove   :%s\n", (char *)memmove(buf1, buf2, len));
// 	return (0);
// }
