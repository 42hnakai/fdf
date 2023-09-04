/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:06:18 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/04 23:43:42 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (i < n && (us1[i] != '\0' || us2[i] != '\0'))
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
// 	printf("ft_strncmp:%d\n", ft_strncmp("aaabcabcd", "a", -1));
// 	printf("strncmp   :%d\n", strncmp("aaabcabcd", "a", -1));
// 	printf("ft_strncmp:%d\n", ft_strncmp("libft-test-tokyo", "-42", 16));
// 	printf("strncmp   :%d\n", strncmp("libft-test-tokyo", "-42", 16));
// 	printf("ft_strncmp:%d\n", ft_strncmp("ABCDEF", "A23456", 3));
// 	printf("strncmp   :%d\n", strncmp("ABCDEF", "A23456", 3));
// 	printf("ft_strncmp:%d\n", ft_strncmp(NULL, "hello", 0));
// 	printf("strncmp   :%d\n", strncmp(NULL, "hello", 0));
// 	return (0);
// }
