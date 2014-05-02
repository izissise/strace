/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define IS_OPCODE(x) (x)

void	strace_print_return()
{
  ;
}

void	strace_print_syscall()
{
  ;
}

int	check_status(pid_t pid)
{
  int	status;

  if (waitpid(pid, &status, 0) == -1)
    return (1);
  if (WIFSIGNALED(status))
    return (1);
  else if (WIFEXITED(status))
    {
      printf(" = ?\n");
      return (1);
    }
  else if (WSTOPSIG(status) == SIGINT)
    {
      ptrace(PTRACE_KILL, pid, NULL, NULL);
      printf("Process %i stopped", pid);
      return (1);
    }
  return (0);
}

void				check_syscall(int pid)
{
  static int			retsys = 0;
  struct user_regs_struct	reg;
  short				value;

  if (ptrace(PTRACE_GETREGS, pid, NULL, &reg))
    return ;
  if (retsys)
    {
      strace_print_return(&reg);
      retsys = 0;
    }
  else
    {
      if ((value = ptrace(PTRACE_PEEKTEXT, pid, reg.rip, NULL)) == -1)
        {
          fprintf(stderr, "ERROR : failed ptrace(PTRACE_PEEKTEXT)\n");
          return ;
        }
      if (IS_OPCODE(value))
        {
          strace_print_syscall(&reg);
          retsys = 1;
        }
    }
}

void	trace_pid(pid_t pid)
{
  ptrace(PTRACE_ATTACH, pid, NULL, NULL);
  while (check_status(pid))
    {
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
      check_syscall(pid);
    }
}

void	ptrace_exec(char *program, char **av)
{
  pid_t	child;
  int	status;

  if ((child = fork()) == -1)
    {
      perror("fork");
      return ;
    }
  else if (child == 0)
    {
      ptrace(PTRACE_TRACEME, child, NULL, NULL);
      if (execvp(program, av) == -1)
        {
          perror(program);
          return ;
        }
    }
  waitpid(child, &status, 0);
  trace_pid(child);
  waitpid(child, &status, 0);
}

void	ptrace_attach(pid_t pid)
{
  if ((pid <= 0) || (kill(pid, 0) == -1))
    {
      perror("pid");
      return ;
    }
  trace_pid(pid);
}

int	main(int ac, char **av)
{
  if ((ac == 3) && (!strcmp("-p", av[1])))
    ptrace_attach(atol(av[2]));
  else if (ac >= 2)
    ptrace_exec(av[1], &(av[2]));
  else
    fprintf(stderr, "USAGE : %s [-p PID] | program name\n", av[0]);
  return (0);
}
