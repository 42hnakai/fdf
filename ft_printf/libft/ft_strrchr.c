/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:06:40 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/28 15:29:28 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + i));
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
// 	const char buf[] = "ABCDEBF";
// 	const char *buf1 = NULL;
// 	printf("ft_strrchr:%s\n", ft_strrchr(buf, 'A'));
// 	printf("strrchr   :%s\n", strrchr(buf, 'A'));
// 	printf("ft_strrchr:%s\n", ft_strrchr(buf, '\0'));
// 	printf("strrchr   :%s\n", strrchr(buf, '\0'));
// 	printf("ft_strrchr:%s\n", ft_strrchr(buf, 'd'));
// 	printf("strrchr   :%s\n", strrchr(buf, 'd'));
// 	printf("ft_strrchr:%s\n", ft_strrchr(buf1, 'd'));
// 	printf("strrchr   :%s\n", strrchr(buf1, 'd'));
// 	return (0);
// }
