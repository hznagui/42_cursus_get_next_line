/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:26 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/06 20:47:43 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *line;
    char *buffer;
    char *ret;
    buffer = malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!buffer)
        return(0);
    while (!ft_strchr(line ,'\n'))
    {
        read(fd,buffer,BUFFER_SIZE);
        line = ft_strjoin(line,buffer);
    }
    ret = ft_substr(line,0,ft_strlen(line) - ft_strlen(ft_strchr(line,'\n')));
    line = ft_strchr(line,'\n');
    return(ret);
}
#include <fcntl.h>
int main()
{
    int p = open("test",O_CREAT | O_RDWR |  O_RDWR,0777);
    // write(p,"hello",5);
    printf("%s",get_next_line(p));
}