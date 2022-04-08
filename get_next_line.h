/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:44:39 by genouf            #+#    #+#             */
/*   Updated: 2022/04/06 14:45:00 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

/* INCLUDE */
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_realloc(char *s1, char *s2);
char	*initialize_buff(int fd, int buff_size);

#endif
