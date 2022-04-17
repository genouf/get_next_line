/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/04/15 21:13:12 by genouf           ###   ########.fr       */
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

int	ft_process(char **buff, char **result, int fd)
{
	int	ret;

	if (buff && ft_strlen(*buff) == 0)
	{
		ret = read(fd, *buff, BUFFER_SIZE);
		if (ret < 1)
			return(0);
		(*buff)[ret] = '\0';
	}
	else
		ret = 1;
	if (ft_find_line(*buff, BUFFER_SIZE) == -1)
	{
		*result = ft_strjoin(*result, *buff);
		ft_bzero(*buff, BUFFER_SIZE);
		ft_process(buff, result, fd);
	}
	else
		ft_splitbuff(buff, result, ft_find_line(*buff, BUFFER_SIZE));
	return(ret);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*buff = NULL;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	result = NULL;
	if (!buff)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return (NULL);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	ft_process(&buff, &result, fd);
	return (result);
}
