/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:29 by genouf            #+#    #+#             */
/*   Updated: 2022/04/10 19:01:59 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoinfinal(char const *s1, char const *s2, int id_line)
{
	size_t	size;
	char	*result;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j < id_line + 1)
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c;
	unsigned char	*p;
	unsigned char	*tmp;
	size_t			i;

	c = (unsigned char *)src;
	p = (unsigned char *)dst;
	tmp = (unsigned char *)malloc(len);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = c[i];
	i = 0;
	while (len > 0)
	{
		*p = tmp[i];
		p++;
		i++;
		len--;
	}
	*p = '\0';
	free(tmp);
	return (dst);
}