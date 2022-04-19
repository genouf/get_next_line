/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/04/19 19:36:17 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_line(char *buff, int buff_size)
{
	int i;

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


char	*get_next_line(int fd)
{
	char			*result;
	static char		*save;
	char			*buff;
	int				ret;
	char 			*tmp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	result = NULL;
	tmp = NULL;
	buff = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	if (ft_strlen(save) > 0)
	{
		buff = ft_strjoin(buff, save);
		free(save);
		save = NULL;
		ret = 1;
	}
	else
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 1)
		{
			free(buff);
			return (0);
		}
	}
	while (ret && ft_find_line(buff, BUFFER_SIZE) == -1)
	{
		result = ft_strjoin(result, buff);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
	}
	if (ret)
	{
		tmp = ft_subuff(buff, ft_find_line(buff, BUFFER_SIZE));
		result = ft_strjoin(result, tmp);
		free(tmp);
		save = ft_substr(buff, ft_find_line(buff, BUFFER_SIZE) + 1);
	}
	free(buff);
	return (result);
}
