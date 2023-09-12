/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:00 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/06 17:20:00 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	while (i + len_dst + 1 < dstsize && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

// #include <bsd/string.h>
// #include <stddef.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }

// int main(void)
// {
// 	// char *ft_buf1 = NULL;
// 	// char ft_buf2[] = "123456";
// 	char *buf1 = NULL;
// 	char buf2[] = "123456";
// 	size_t dstsize = 0;
// 	// printf("ft_strlcat:%zu\n", ft_strlcat(ft_buf1, ft_buf2, dstsize));
// 	// printf("ft_strlcat:%s\n", ft_buf1);
// 	printf("strlcat:%zu\n", strlcat(buf1, buf2, dstsize));
// 	printf("strlcat:%s\n", buf1);
// 	return (0);
// }
