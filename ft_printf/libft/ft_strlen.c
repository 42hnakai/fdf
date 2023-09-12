/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:42:28 by hnakai            #+#    #+#             */
/*   Updated: 2022/07/11 16:42:28 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char *a = "0000000000";
// 	printf("ft_strlen : %zu\n", ft_strlen(a));
// 	printf("strlen : %zu\n", strlen(a));
// 	return (0);
// }
