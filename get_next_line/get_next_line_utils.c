/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 00:02:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 23:06:42 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
		return (ft_strlen1(src));
	if (src == NULL)
		return (0);
	while (count + 1 < dstsize && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen1(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen1(s);
	if (start >= len_s)
	{
		a = (char *)malloc(sizeof(char));
		if (!a)
			return (NULL);
		a[0] = '\0';
		return (a);
	}
	if (len > len_s - start)
		len = len_s - start;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	gnl_ft_strlcpy(a, s + start, len + 1);
	return (a);
}

size_t	ft_strlen1(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	gnl_ft_strlcpy(str, s1, ft_strlen1(s1) + 1);
	gnl_ft_strlcpy(str + ft_strlen1(s1), s2, ft_strlen1(s1) + ft_strlen1(s2)
		+ 1);
	free(s1);
	return (str);
}
