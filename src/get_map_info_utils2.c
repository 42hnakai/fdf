/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:33:42 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:44:25 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_elems_ary(char *line)
{
	char	*line_no_nl;
	char	**elems_ary;

	line_no_nl = ft_strtrim(line, "\n");
	free(line);
	elems_ary = ft_split(line_no_nl, ' ');
	free(line_no_nl);
	return (elems_ary);
}
