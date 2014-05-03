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

pid_t	ptrace_exec(char *program, char **av)
{
  pid_t	child;

  if ((child = fork()) == -1)
    {
      perror("fork");
      return (-1);
    }
  else if (child == 0)
    {
      if ((ptrace(PTRACE_TRACEME, child, NULL, NULL) == -1)
          || (raise(SIGSTOP)) || (execvp(program, av) == -1))
        {
          perror(program);
          exit(1);
        }
      exit(1);
    }
  return (child);
}

pid_t	ptrace_attach(pid_t pid)
{
  if ((pid <= 0) || (kill(pid, 0) == -1))
    {
      if (pid <= 0)
        errno = ESRCH;
      perror("pid");
      return (-1);
    }
  if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
    {
      perror("ptrace");
      return (-1);
    }
  return (pid);
}

int	main(int ac, char **av)
{
  pid_t	pid;

  pid = 0;
  if ((ac == 3) && (!strcmp("-p", av[1])))
    pid = ptrace_attach(atol(av[2]));
  else if (ac >= 2)
    pid = ptrace_exec(av[1], &(av[1]));
  else
    fprintf(stderr, "USAGE : %s [-p PID] | program name\n", av[0]);
  if (pid > 0)
    trace_pid(pid);
  else
    return (1);
  return (0);
}
