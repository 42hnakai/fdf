/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:06:05 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/05 18:23:09 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
// 	const char buf[] = "ABCDEF";
// 	const char *buf1 = NULL;
// 	printf("ft_strchr:%s\n", ft_strchr(buf, 'C'+ 256));
// 	printf("strchr   :%s\n", strchr(buf, 'C' + 256));
// 	printf("ft_strchr:%s\n", ft_strchr(buf, 0));
// 	printf("strchr   :%s\n", strchr(buf, 0));
// 	printf("ft_strchr:%s\n", ft_strchr(buf, 'D'));
// 	printf("strchr   :%s\n", strchr(buf, 'D'));
// 	printf("ft_strchr:%s\n", ft_strchr(buf1, 'd'));
// 	printf("strchr   :%s\n", strchr(buf1, 'd'));
// 	return (0);
// }
