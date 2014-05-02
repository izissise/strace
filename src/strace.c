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


void	strace_print_return()
{
  ;
}

void	strace_print_syscall()
{
  ;
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

int	check_status(pid_t pid)
{
  int	status;

  if (waitpid(pid, &status, 0) == -1)
    return (1);
  if (WIFEXITED(status))
    {
      printf("exit_group(%d) = ?\n", WEXITSTATUS(status));
      return (1);
    }
  else if (WIFSIGNALED(status))
    {
      printf("Signal: %d\n", WIFSTOPPED(status) ?
             WSTOPSIG(status) : WTERMSIG(status));
    }
  return (0);
}

void	trace_pid(pid_t pid)
{
  while (!check_status(pid))
    {
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
        perror("ptrace");
      check_syscall(pid);
      if (ptrace(PTRACE_CONT, pid, NULL, NULL) == -1)
        perror("ptrace");
    }
//  if (ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1)
//    perror("ptrace");
}
