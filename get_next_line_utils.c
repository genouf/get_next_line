/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:29 by genouf            #+#    #+#             */
/*   Updated: 2022/04/19 19:25:13 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	free(s1);
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

char	*ft_substr(char *s, unsigned int start)
{
	char	*result;
	size_t	i;
	size_t	size;

	size = ft_strlen(s + start);
	i = 0;
	if (size == 0)
		return (0);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_subuff(char *buff, int	id_line)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (id_line + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < id_line + 1)
	{
		result[i] = buff[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	
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
