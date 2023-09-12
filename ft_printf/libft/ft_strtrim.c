/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:01:00 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 19:33:21 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	if (s1[i] != '\0')
	{
		while (ft_strchr(set, s1[j - 1]) != NULL && (j - 1) > i)
			j--;
	}
	s2 = ft_substr(s1, i, j - i);
	return (s2);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	printf("%s \n",ft_strtrim("tripouille   xxx", " x"));
// 	return (0);
// }