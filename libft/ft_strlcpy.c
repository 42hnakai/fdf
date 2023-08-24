/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:25 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/06 17:20:25 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (src == NULL)
		return (0);
	while (count + 1 < dstsize && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stddef.h>

// int main(void)
// {
// 	char ft_buf1[] = "ABCEDF";
// 	char ft_buf2[] = "123456";
// 	char buf1[] = "ABCDEF";
// 	char buf2[] = "123456";
// 	size_t dstsize = 7;
// 	printf("ft_strlcpy:%lu\n", ft_strlcpy(ft_buf1, ft_buf2, dstsize));
// 	printf("ft_strlcpy:%s\n", ft_buf1);
// 	printf("strlcpy:%lu\n", strlcpy(buf1, buf2, dstsize));
// 	printf("strlcpy:%s\n", buf1);
// 	return (0);
// }