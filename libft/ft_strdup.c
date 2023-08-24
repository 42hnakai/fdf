/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:59:24 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/11 23:21:51 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}

// #include <string.h>

// int main(void)
// {
// 	// const char s[] = "ABCDEF";
// 	printf("%s \n", ft_strdup(NULL));
// 	printf("%s \n", strdup(NULL));
// 	return (0);
// }
