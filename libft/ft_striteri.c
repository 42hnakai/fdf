/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:38:48 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/12 12:05:22 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

// void	iter(unsigned int i, char *s)
// {
// 	*s += i;
// }

// int	main(void)
// {
// 	char s[] = "0000000000";
// 	ft_striteri(s, iter);
// 	printf("%s", s);
// }