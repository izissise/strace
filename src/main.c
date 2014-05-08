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

static int	*g_quit;

void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      (*g_quit) = 1;
    }
}

pid_t	ptrace_exec(char *program, char **av, char **envp, t_strace *trace)
{
  pid_t	child;
  char	*path;

  if (!(path = prog_full_path(program)))
    return (-1);
  if ((child = fork()) == -1)
    {
      perror("fork");
      free(path);
      return (-1);
    }
  else if (child == 0)
    {
      if ((ptrace(PTRACE_TRACEME, child, NULL, NULL) == -1)
          || (raise(SIGSTOP)) || (execve(path, av, envp) == -1))
        {
          perror(program);
          exit(1);
        }
      exit(1);
    }
  trace->bit = is_64_bit_path(path);
  free(path);
  trace->forked = 1;
  return (child);
}

pid_t	ptrace_attach(pid_t pid, t_strace *trace)
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
  trace->bit = is_64_bit_pid(pid);
  trace->forked = 0;
  return (pid);
}

int		main(int ac, char **av, char **envp)
{
  t_strace	trace;

  trace.bit = 1;
  trace.pid = 0;
  trace.quit = 0;
  g_quit = &(trace.quit);
  if ((ac == 3) && (!strcmp("-p", av[1])))
    trace.pid = ptrace_attach(atol(av[2]), &trace);
  else if (ac >= 2)
    trace.pid = ptrace_exec(av[1], &(av[1]), envp, &trace);
  else
    fprintf(stderr, "USAGE : %s [-p PID] | program name\n", av[0]);
  if (trace.pid > 0)
    {
      if (!trace.forked)
        signal(SIGINT, &sig_handler);
      trace_pid(&trace);
    }
  else
    return (1);
  return (0);
}
