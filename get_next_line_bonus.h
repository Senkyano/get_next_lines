#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_stock
{
	char	*rest;
	char	*curr;
	char	*line;
}	t_stock;

char	*get_next_line(int fd);
char	*ft_readfile(int fd, char *rest);
char	*ft_join(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_line(char *curr);
char	*ft_aftline(char *curr);

#endif
