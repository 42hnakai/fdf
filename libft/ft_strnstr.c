/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:06:28 by hnakai            #+#    #+#             */
/*   Updated: 2022/09/29 09:26:39 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_len;

	if (find[0] == '\0')
		return ((char *)str);
	find_len = ft_strlen(find);
	while (find_len <= len-- && *str != '\0')
	{
		if (ft_strncmp(str, find, find_len) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

// #include <bsd/string.h>

// int main(void)
// {
// 	printf("ft_strnstr:%s\n", ft_strnstr("AAABCDEF", "AABC", 5));
// 	printf("strnstr   :%s\n", strnstr("AAABCDEF", "AABC", 5));
// 	printf("ft_strnstr:%s\n", ft_strnstr("", "ABCDE", -1));
// 	printf("strnstr   :%s\n", strnstr("", "ABCDE", 3));
// 	printf("ft_strnstr:%s\n", ft_strnstr("aaabcabcd", "a", -1));
// 	printf("strnstr   :%s\n", strnstr("aaabcabcd", "a", -1));
// 	printf("ft_strnstr:%s\n", ft_strnstr(NULL, "1", 0));
// 	printf("strnstr   :%s\n", strnstr(NULL, "1", 0));
// 	printf("ft_strnstr:%s\n", ft_strnstr("1", "", 0));
// 	printf("strnstr   :%s\n", strnstr("1", "", 0));
// 	return (0);
// }
