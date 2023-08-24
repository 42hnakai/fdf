/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:58:31 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/10 00:26:49 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	n;

	if (count == 0 || size == 0)
		n = 1;
	else if (size > SIZE_MAX / count)
		return (NULL);
	else
		n = size * count ;
	s = (void *)malloc(sizeof(void) * n);
	if (!s)
		return (NULL);
	ft_memset(s, 0, n);
	return (s);
}

// int main(void)
// {
// 	printf("%p", ft_calloc(0, 0));
// 	return (0);
// }
