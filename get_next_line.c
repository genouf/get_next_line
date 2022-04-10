/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/04/10 21:22:41 by genouf           ###   ########.fr       */
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

char *ft_good_buffer(char *buff, int id_line, int fd, int *ret, char **result)
{
	if (id_line < 0)
	{
		*result = ft_strjoin(*result, buff);
		*ret = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		if (!(*ret))
			return(*result);
		ft_good_buffer(buff, ft_find_line(buff, BUFFER_SIZE), fd, ret, result);
	}
	else
	{
		//printf("%d", id_line);
		*result = ft_strjoinfinal(*result, buff, id_line);
		buff = ft_memmove(buff, buff + id_line + 1, BUFFER_SIZE - id_line);
	}
	return (*result);
}

char	*ft_process(char *buff, int fd)
{
	char	*result;
	int		ret;

	result = 0;
	//printf("my buff:%s\n", buff);
	ft_good_buffer(buff, ft_find_line(buff, BUFFER_SIZE), fd, &ret, &result);
	if (ret == 0)
	{
		printf("ici");
		free(buff);
	}
	return(result);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*buff = NULL;
	int	ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	result = 0;
	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		if (!ret)
		{
			free(buff);
			return (NULL);
		}
		result = ft_process(buff, fd);
	}
	else
		result = ft_process(buff, fd);
	return (result);
}
