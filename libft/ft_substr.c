/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:02 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/10 00:29:26 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
	{
		a = malloc(sizeof(char) * 1);
		if (!a)
			return (NULL);
		a[0] = '\0';
		return (a);
	}
	if (len > len_s - start)
		len = len_s - start;
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s + start, len + 1);
	return (a);
}

// int main(void)
// {
// 	// const char s[] = "ABCDEF";
// 	printf("%s \n", ft_substr(NULL, 3, 1));
// 	return (0);
// }