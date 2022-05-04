/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/04/25 15:42:44 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (i + 1 < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_find_line(char *buff, int buff_size)
{
	int	i;

	i = 0;
	while (buff[i] && i < buff_size)
	{
		if (buff[i] == '\n')
		{
			return (i);
		}	
		i++;
	}
	return (-1);
}

char	*initialize_buff(int *ret, char **save, int fd)
{
	char	*new_buff;

	new_buff = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (new_buff == NULL)
		return (NULL);
	if (*save)
	{
		ft_strlcpy(new_buff, *save, BUFFER_SIZE + 1);
		free(*save);
		*save = 0;
		*ret = 1;
	}
	else
	{
		*ret = read(fd, new_buff, BUFFER_SIZE);
		if (*ret < 1)
		{
			free(new_buff);
			return (0);
		}
	}
	return (new_buff);
}

char	*process_line(char *result, char *buff, int	*ret, int fd)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (*ret && ft_find_line(buff, BUFFER_SIZE) == -1)
	{
		tmp = result;
		result = ft_strjoin(tmp, buff);
		*ret = read(fd, buff, BUFFER_SIZE);
		buff[*ret] = '\0';
		free(tmp);
	}
	if (ret)
	{
		tmp = ft_subuff(buff, ft_find_line(buff, BUFFER_SIZE));
		tmp2 = result;
		result = ft_strjoin(result, tmp);
		free(tmp);
		free(tmp2);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*save[1024];
	char			*buff;
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	result = NULL;
	buff = initialize_buff(&ret, &save[fd], fd);
	if (buff == NULL)
		return (NULL);
	result = process_line(result, buff, &ret, fd);
	if (ret)
		save[fd] = ft_substr(buff, ft_find_line(buff, BUFFER_SIZE + 1));
	free(buff);
	return (result);
}
