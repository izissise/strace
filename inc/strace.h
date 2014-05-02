/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#ifndef STRACE_H_INCLUDED
# define STRACE_H_INCLUDED

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define IS_OPCODE(x) (x)

typedef struct	syscall_info
{
  char		*name;
  int		number;
  char		*ret;
  int		nbargs;
  char		*args;
}		t_syscall_info;

void	trace_pid(pid_t pid);

#endif /* !STRACE_H_INCLUDED */
