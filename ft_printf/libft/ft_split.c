/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:02:38 by hnakai            #+#    #+#             */
/*   Updated: 2022/10/11 23:19:09 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (ft_strncmp(&s[i], &c, 1) == 0)
		{
			while (ft_strncmp(&s[i], &c, 1) == 0 && s[i] != '\0')
				i++;
		}
		else
		{
			while (ft_strncmp(&s[i], &c, 1) != 0 && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

static size_t	*ft_s_info(char const *s, char c, size_t count)
{
	size_t	*s_info;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s_info = malloc(sizeof(size_t) * (count * 2 + 1));
	if (!s_info)
		return (NULL);
	while (s[i] != '\0')
	{
		while (ft_strncmp(&s[i], &c, 1) == 0 && s[i] != '\0')
			i++;
		s_info[j] = i;
		j++;
		while (ft_strncmp(&s[i], &c, 1) != 0 && s[i] != '\0')
			i++;
		s_info[j] = i - s_info[j - 1];
		j++;
	}
	return (s_info);
}

static char	**ft_free(char **s1, size_t *s_info, size_t n)
{
	size_t	j;

	j = 0;
	free(s_info);
	while (j < n)
	{
		free(s1[j]);
		j++;
	}
	if (!s1)
		free(s1);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	size_t	*s_info;
	size_t	i;

	if (!s)
		return (NULL);
	s_info = ft_s_info(s, c, ft_count(s, c));
	if (!s_info)
		return (NULL);
	i = 0;
	s1 = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (s1 == NULL)
		return (ft_free(s1, s_info, 0));
	while (i < ft_count(s, c))
	{
		s1[i] = malloc(sizeof(char) * (s_info[i * 2 + 1] + 1));
		if (s1[i] == NULL)
			return (ft_free(s1, s_info, i));
		ft_strlcpy(s1[i], s + s_info[i * 2], s_info[i * 2 + 1] + 1);
		i++;
	}
	s1[i] = NULL;
	free(s_info);
	return (s1);
}

// #include <stdio.h>

// int main(void)
// {
// 	size_t i = 0;
// 	char **tab = ft_split("  tripouille  42  ", ' ');
// 	while (i < 3)
// 	{
// 		printf("%s", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }