/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:26 by hznagui           #+#    #+#             */
/*   Updated: 2022/11/07 17:53:22 by hznagui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    if (fd < 0 | BUFFER_SIZE <= 0)
        return(0);
    static char *line;
    char *buffer;
    char *ret;
    int  readvl;
    buffer = malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!buffer)
        return(0);
    while (!ft_strchr(line,'\n'))
    {
        readvl = read(fd,buffer,BUFFER_SIZE);
        if (readvl <= 0)
        {
            if (!line)
            {
                free(buffer);
                return (NULL);
            }
            else
                return(free(buffer),buffer = NULL,free(line),line = NULL,NULL);
            break;
        }
        free(line);
        line = ft_strjoin(line,buffer);
    }
    if (ft_strchr(line, '\n'))
    {
        ret = ft_substr(line,0,ft_strlen(line) - ft_strlen(ft_strchr(line,'\n')));
        free(line);
        line = ft_strdup(ft_strchr(line, '\n'));
        // line = temp;
    }
    else
    {
        ret = ft_strdup(line);
        free(line);
        line =  NULL;
    }
    free(buffer);
    return (ret);
}


// #include <fcntl.h>
// int main()
// {
//     int p = open("test",O_CREAT | O_RDWR |  O_RDWR,0777);
//     char *pp;
//     // write(p,"hello",5);
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);

//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
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
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     printf("\n\n\n");
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);    
//     pp =get_next_line(p);
//     printf("%s",pp);
//     free(pp);

//     system("leaks a.out");
// }