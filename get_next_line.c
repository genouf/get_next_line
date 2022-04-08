/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/04/06 14:45:16 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line_core(int fd, char *buff, char *result)
{
	int	ret;
	int	i;

	ret = 1;
	while (ret)
	{
		i = -1;
		while (ret && ++i < BUFFER_SIZE)
		{
			ret = read(fd, buff + i, 1);
			if (ret == -1)
				return (0);
			if (*(buff + i) == '\n')
				ret = 0;
		}
		result = ft_realloc(result, buff);
	}
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	char	*result;
	char	*buff;

	result = 0;
	buff = initialize_buff(fd, BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	else
		result = ft_realloc(result, buff);
	return (next_line_core(fd, buff, result));
}
