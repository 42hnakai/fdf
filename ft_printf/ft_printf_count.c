/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:59:03 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/07 21:37:49 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_count(unsigned long long int ullx)
{
	int	count;

	count = 0;
	while (ullx >= 16)
	{
		count++;
		ullx = ullx / 16;
	}
	count++;
	return (count);
}
