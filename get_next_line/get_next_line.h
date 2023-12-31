/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:06:58 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/12 22:16:07 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*ft_readbuff(char *buff, int fd);
size_t	ft_count(char *buff);
char	*ft_make_buff(char *save, int fd);
char	*ft_make_save(char *buff);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen1(const char *str);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif