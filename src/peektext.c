/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#include "strace.h"

int	peek_proc_data(pid_t pid, void *addr, short *res)
{
  errno = 0;
  if ((((*res) = ptrace(PTRACE_PEEKTEXT, pid, addr, NULL)) == -1)
      && (errno != 0))
    {
      perror("Ptrace");
      return (1);
    }
  return (0);
}