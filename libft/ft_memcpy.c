/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:18:52 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/11 13:18:52 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*udst;
	const unsigned char	*usrc;

	if (dst == src || n == 0)
		return (dst);
	udst = (unsigned char *)dst;
	usrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *buf1 = NULL;
// 	char *buf2 = NULL;
// 	char buf2[]="12345";
// 	printf("memcpy:%p", memcpy(buf1, buf2, 3));
// 	printf("memcpy:%p", memcpy(NULL, "ABCEDF", 2));
// }