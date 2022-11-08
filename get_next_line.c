/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:26 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/08 22:44:32 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_line(char *save)
// {
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	if (!save[i])
// 		return (NULL);
// 	while (save[i] && save[i] != '\n')
// 		i++;
// 	s = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (save[i] && save[i] != '\n')
// 	{
// 		s[i] = save[i];
// 		i++;
// 	}
// 	if (save[i] == '\n')
// 	{
// 		s[i] = save[i];
// 		i++;
// 	}
// 	s[i] = '\0';
// 	return (s);
// }

// char	*ft_save(char *save)
// {
// 	int		i;
// 	int		c;
// 	char	*s;

// 	i = 0;
// 	while (save[i] && save[i] != '\n')
// 		i++;
// 	if (save[i] == 0)
// 	{
// 		free(save);
// 		return (NULL);
// 	}
// 	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
// 	if (!s)
// 		return (NULL);
// 	if (save[i] == '\n')
// 		i++;
// 	c = 0;
// 	while (save[i])
// 		s[c++] = save[i++];
// 	s[c] = '\0';
// 	free(save);
// 	return (s);
// }

// char	*my_read(int fd, char *save)
// {
// 	char	*buff;
// 	int		read_bytes;

// 	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	read_bytes = 1;
// 	while (new_line(save, '\n') == 0 && read_bytes != 0)
// 	{
// 		read_bytes = read(fd, buff, BUFFER_SIZE);
// 		if (read_bytes == -1)
// 		{
// 			free(save);
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[read_bytes] = '\0';
// 		save = ft_strjoin(save, buff);
// 	}
// 	free(buff);
// 	return (save);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*save;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	save = my_read(fd, save);
// 	if (!save)
// 		return (NULL);
// 	line = get_line(save);
// 	save = ft_save(save);
// 	return (line);
// }
/*****************************************************************************************/
char *get_next_line(int fd)
{
    if (fd < 0 | BUFFER_SIZE <= 0)
        return(0);
    static char *line;
    char *ret =NULL;
    char *buffer;
    int readvl=1;
    
    buffer = malloc((BUFFER_SIZE) *sizeof(char));
    if (!buffer)
        return(0);
    while (!ft_strchr(line ,'\n') && readvl > 0)
    {
        readvl = read(fd,buffer,BUFFER_SIZE);
        line = ft_strjoin(line,buffer);
    }
    if(ft_strchr(line ,'\n'))
    {
        ret = ft_substr(line ,0,ft_strlen(line) - ft_strlen(ft_strchr(line ,'\n')));
        ft_strlcpy (line,ft_strchr(line ,'\n'),ft_strlen(ft_strchr(line ,'\n')));
        printf("[ha lghalat]");
    }
    else if (readvl <= 0 && !line)
        return (free(buffer),NULL);
    else if(readvl <= 0)
        return(free(buffer),buffer = NULL,NULL);
    return (free(buffer),buffer = NULL,ret);
}



// int main()
// {
//     int p = open("test001",O_CREAT | O_RDWR |  O_RDWR,0777);
//     char *pp;
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     printf("\n\n");

//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     printf("\n\n");
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//         pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     // system("leaks a.out");
// }
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // printf("\n\n\n");
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);    
    // pp =get_next_line(p);
    // printf("%s",pp);
    // free(pp);

// }