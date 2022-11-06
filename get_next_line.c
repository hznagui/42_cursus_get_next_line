/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:26 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/06 18:43:24 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *line;
    char *buffer;
    buffer=malloc((BUFFER_SIZE + 1)*sizeof(char));
    while (!ft_strchr(line ,'\n'))
    {
        read(fd,buffer,BUFFER_SIZE);
        line = ft_strjoin(line,buffer);
    }
    return(line);
}
#include <fcntl.h>
int main()
{
    int p = open("test",O_RDWR |  O_RDWR,0777);
    write(p,"hello",5);
    // get_next_line(p);
}