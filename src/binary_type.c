/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "strace.h"

int	is_64_bit(pid_t pid)
{
  int	fd;
  int	tmp;
  char	path[512];

  snprintf(path, sizeof(path), "/proc/%lu/exe", (long int)pid);
  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (2);
  tmp = read(fd, path, 10);
  close(fd);
  if (tmp < 6)
    return (3);
  if (path[4] == 1)
    return (0);
  return (1);
}
