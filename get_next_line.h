/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:19:28 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/14 13:58:24 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// REMOOOOOVE BEFORE PUSHING
# include <stdio.h>


char 	*get_next_line(int fd);
size_t	ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_substr(char *accumulation, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
char *ft_strjoin(char *accumulation, char *buffer);
char *ft_strdup(const char *s1);

#endif