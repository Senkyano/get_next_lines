#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlen(const char *str);
int		ft_srchcara(const char *str, int c);
char	*ft_cpyrest(char *str);
char	*get_next_line(int fd);
char	*ft_strjointo(char *s1, char *s2, ssize_t to);

#endif