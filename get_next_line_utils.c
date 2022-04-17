/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:29 by genouf            #+#    #+#             */
/*   Updated: 2022/04/14 13:52:08 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i] == '\0')
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
	while (s1 && s1[i] == '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] == '\0')
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	if (size < len)
		len = size;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (start < (unsigned int)ft_strlen((char *)s))
	{
		while (i < len)
		{
			result[i] = s[start];
			i++;
			start++;
		}
	}
	result[i] = '\0';
	return (result);
}

void	ft_splitbuff(char **buff, char **result, int id_line)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (id_line + 1));
	if (tmp == NULL)
		return ;
	i = 0;
	while (i < id_line + 1)
	{
		tmp[i] = (*buff)[i];
		i++;
	}
	*result = ft_strjoin(*result, tmp);
	free(tmp);
	*buff = ft_substr(*buff, id_line + 1, BUFFER_SIZE - (id_line + 1));
}