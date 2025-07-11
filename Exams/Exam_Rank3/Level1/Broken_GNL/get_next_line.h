#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char    *get_next_line(int fd);
char    *ft_strchr(char *s, int c);
size_t  ft_strlen(char *s);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
int     str_append_mem(char **s1, char *s2, size_t size2);
int     str_append_str(char **s1, char *s2);

#endif
