/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:38 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/08 22:42:55 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*---------------------------1-------------------------------------*/
static size_t	leakskiller(char *s, unsigned int start, size_t len)
{
	if (ft_strlen(s + start) >= len)
	{
		return (len);
	}
	else
	{
		return (ft_strlen(s + start));
	}
}

char	*ft_substr(char*s, unsigned int start, size_t len)
{
	size_t	o;
	char	*p;

	if (!s)
		return (0);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	p = malloc((leakskiller(s, start, len) + 1) * sizeof(char));
	if (!p)
		return (0);
	o = 0;
	while (o < len && s[start + o])
	{
		p[o] = s[start + o];
		o++;
	}
	p[o] = '\0';
	return (p);
}
/*---------------------------2-------------------------------------*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[i] = '\0';
	free(s1);
	return (str);
}
/*---------------------------3-------------------------------------*/
char	*ft_strchr(char *s, int c)
{
	int		i;
	int		o;
	char	*u;

	if (!s)
		s = "";
		u = (char *)s;
	i = 0;
	o = ft_strlen(s);
	while (i <= o)
	{
		if (s[i] == (char)c)
			return (u + i + 1 );
		i++;
	}
	return (0);
}
/*---------------------------4-------------------------------------*/
char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	y;
	char	*f;

	y = 0;
	i = ft_strlen(s1);
	f = malloc((i + 1) * sizeof(char));
	if (!f)
		return (0);
	while (y < i)
	{
		f[y] = s1[y];
		y++;
	}
	f[y] = '\0';
	return (f);
}
/*---------------------------5-------------------------------------*/
size_t	ft_strlcpy(char *dst,char *src, size_t dstsize)
{
	size_t	i;
	size_t	u;

	u = 0;
	i = 0;
	while (src[i])
		i++;
	if (dstsize <= 0)
		return (i);
	while (u < i && u < dstsize - 1)
	{
		dst[u] = src[u];
		u++;
	}
	dst[u] = '\0';
	return (i);
}
int	new_line(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}