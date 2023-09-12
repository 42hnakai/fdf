/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:06:48 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/08 04:30:37 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

// #include <ctype.h>

// int main(void)
// {
// 	printf("ft_tolower:%c\n", ft_tolower('f'));
// 	printf("tolower   :%c\n", tolower('f'));
// 	printf("ft_tolower:%c\n", ft_tolower('b'));
// 	printf("tolower   :%c\n", tolower('b'));
// 	printf("ft_tolower:%c\n", ft_tolower(' '));
// 	printf("tolower   :%c\n", tolower(' '));
// 	return (0);
// }
