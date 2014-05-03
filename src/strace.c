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

int	is_syscall(short opcode)
{
  short	sysc[3];
  int	i;

  i = 0;
  sysc[0] = 0x0f05;
  sysc[1] = 0x0f34;
  sysc[2] = 0xcd80;
  while (i < 3)
    {
      switch_endian(&(sysc[i]), sizeof(short));
      if ((opcode & 0xFFFF) == sysc[i])
        return (1);
      i++;
    }
  return (0);
}

int		check_syscall(int pid)
{
  struct user	infos;
  struct user	ret;
  short		opcode;

  opcode = 0;
  if ((ptrace(PTRACE_GETREGS, pid, NULL, &infos) != -1)
      && (!peek_proc_data(pid, (void*)(infos.regs.rip), &opcode))
      && (is_syscall(opcode)))
    {
      if ((ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
          || (check_status(pid)))
        {
          print_syscall(&infos, NULL);
          return (1);
        }
      if (ptrace(PTRACE_GETREGS, pid, NULL, &ret) == -1)
        {
          print_syscall(&infos, NULL);
          return (1);
        }
      print_syscall(&infos, &ret);
    }
  return (0);
}

int	check_status(pid_t pid)
{
  int	status;

  if (waitpid(pid, &status, WUNTRACED) == -1)
    return (1);
  if (WIFEXITED(status))
    {
      return (1);
    }
  else if (WIFSIGNALED(status))
    {
      dprintf(STDERR_FILENO, "Signal: %d\n", WIFSTOPPED(status) ?
              WSTOPSIG(status) : WTERMSIG(status));
    }
  return (0);
}

void	trace_pid(pid_t pid)
{
  while (!check_status(pid))
    {
      if (!check_syscall(pid))
        if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
          perror("ptrace");
    }
}
