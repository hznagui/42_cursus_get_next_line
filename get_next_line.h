/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:35 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/09 17:51:03 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(char *s,char p);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst,char *src, size_t dstsize);
int	new_line(char *s, int c);
#endif