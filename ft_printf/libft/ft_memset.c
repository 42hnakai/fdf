/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:34:09 by hnakai            #+#    #+#             */
/*   Updated: 2022/08/03 11:34:09 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*ubuf;
	unsigned char	uch;

	ubuf = (unsigned char *)buf;
	uch = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		*(ubuf + i) = uch;
		i++;
	}
	return (buf);
}
