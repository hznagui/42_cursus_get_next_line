/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:26 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/09 21:08:17 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_ch(char *s, int c)
{
	int		i;
	int		o;
	char	*u;

	if (!s)
		return (NULL);
	u = (char *)s;
	i = 0;
	o = ft_strlen(s, '\0');
	while (i <= o)
	{
		if (s[i] == (char)c)
			return (u + i + 1);
		i++;
	}
	return (0);
}

static char	*reading_line(int fd, char *line)
{
	char	*buffer;
	int		readvl;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_ch(line, '\n'))
	{
		readvl = read(fd, buffer, BUFFER_SIZE);
		if (readvl == -1)
			return (free(line), free(buffer), NULL);
		else if (!readvl && !line)
			return (free(buffer), NULL);
		else if (!readvl)
			return (free(buffer), line);
		buffer[readvl] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = NULL;
	line = reading_line(fd, line);
	if (!line)
		return (NULL);
	else if (!line[0])
		return (free(line), NULL);
	ret = ft_substr(line, 0,
			ft_strlen(line, '\0') - ft_strlen(ft_ch(line, '\n'), '\0'));
	tmp = ft_strdup(line);
	free (line);
	line = ft_strdup(ft_ch(tmp, '\n'));
	free (tmp);
	return (ret);
}
