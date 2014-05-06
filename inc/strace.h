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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/ptrace.h>
# include <sys/user.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define UNSEDP __attribute__((unused))

typedef struct	s_syscall_info
{
  char		*name;
  char		*ret;
  char		*args[9];
}		t_syscall_info;

typedef struct	s_type_map
{
  char		*type;
  void		(*conv)(long long int reg, char res[BUFSIZ], pid_t pid);
}		t_type_map;

void	trace_pid(pid_t pid);
int	peek_proc_data(pid_t pid, void *addr, short *res);
int	check_status(pid_t pid);
void	*switch_endian(void *var, int varsize);
void	print_syscall(struct user *infos, struct user *ret, pid_t pid);

#endif /* !STRACE_H_INCLUDED */
