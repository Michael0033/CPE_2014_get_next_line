/*
** get_next_line.c for get_next_line in /home/besnai_m/rendu/CPE_2014_get_next_line
**
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
**
** Started on  Mon Nov 17 11:34:40 2014 michael besnainou
** Last update Thu Apr  7 19:03:32 2016 michael besnainou
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_strcpy(char *dest, char *src, int n, int end)
{
  int	i;

  i = 0;
  while (i != end)
    {
      dest[n] = src[i];
      i = i + 1;
      n = n + 1;
    }
  return (dest);
}

char		*get_next_line(const int fd)
{
  int		error;
  static char	tab[BUFFER_SIZE];
  char		*line;
  static int	i;
  int		n;

  n = 0;
  line = malloc(BUFFER_SIZE * 2);
  error = 1;
  while (error > 0)
    {
      error = read(fd, tab,  BUFFER_SIZE);
      tab[BUFFER_SIZE] = 0;
      while (tab[i] != '\0')
	{
	  if (tab[i] == '\n')
	    {
	      line = my_strcpy(line, tab, n, i);
	      i = i + 1;
	      return (line);
	    }
	  i = i + 1;
	}
      i = 0;
    }
  return (0);
}
