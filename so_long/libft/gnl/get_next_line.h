/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:51:50 by willda-s          #+#    #+#             */
/*   Updated: 2025/04/23 20:59:43 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>

char	*get_next_line(int fd);

char	*ft_strccpy(char *dst, char *src);

size_t	ft_strrlen(const char *str);

char	*ft_strjjoin(char *s1, char const *s2);

int		ft_strcchr(const char *str, int c);

char	*ft_strddup(char *dst, char *src);

#endif