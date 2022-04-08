/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:29 by genouf            #+#    #+#             */
/*   Updated: 2022/04/08 10:41:10 by genouf           ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	if (i > dstsize)
		return (ft_strlen(src) + dstsize);
	j = 0;
	while (src[j] && (i + j + 1 < dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

char	*ft_realloc(char *s1, char *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	size;
	char	*result;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	size = s1_size + s2_size + 1;
	result = (char *)malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	if (s1 != 0)
		ft_strlcat(result, s1, size);
	ft_strlcat(result, s2, size);
	ft_bzero(s2, s2_size);
	if (s1_size != 0)
		free(s1);
	return (result);
}

char	*initialize_buff(int fd, int buff_size)
{
	char	*buff;
	int		ret;

	if (fd == -1)
		return (0);
	buff = (char *)malloc(sizeof(char) * buff_size);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, buff_size);
	ret = read(fd, buff, 1);
	if (ret == 0 || ret == -1)
	{
		free(buff);
		return (0);
	}
	else
		return (buff);
}
