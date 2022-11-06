/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:03:38 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/06 22:43:03 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*---------------------------1-------------------------------------*/
static size_t	leakskiller(char const *s, unsigned int start, size_t len)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
static char	*ft_return(char *p, char const *s1, char const *s2)
{
	size_t	y;
	size_t	a;

	a = 0;
	y = 0;
	while (y < ft_strlen(s1))
	{
		p[y] = s1[y];
		y++;
	}
	while (a <= ft_strlen(s2))
	{
		p[y + a] = s2[a];
		a++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (0);
	return (ft_return(p, s1, s2));
}
/*---------------------------3-------------------------------------*/
char	*ft_strchr(const char *s, int c)
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
			return (u + i + 1);
		i++;
	}
	return (0);
}
/*---------------------------4-------------------------------------*/
char	*ft_strdup(const char *s1)
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
