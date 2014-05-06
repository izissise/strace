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
#include "syscall_x86_x64.h"
#include "type_map.h"
#include "errno_map.h"

void	handle_error_case(char res[BUFSIZ], long long int rax)
{
  int	err;

  if (rax < 0)
    {
      err = -rax;
      if (err < (int)(sizeof(g_errnomap) / sizeof(char*)))
        snprintf(res, BUFSIZ, "-1 %s (%s)", g_errnomap[err], strerror(err));
    }
}

void	fill_with_type_value(char *type, long long int reg,
                           char res[BUFSIZ], pid_t pid)
{
  int	i;

  i = 0;
  while (i < (int)(sizeof(g_typemap) / sizeof(t_type_map)))
    {
      if (!strcmp(type, g_typemap[i].type))
        {
          (g_typemap[i].conv)(reg, res, pid);
          return ;
        }
      i++;
    }
  snprintf(res, BUFSIZ, "Unknow type %s", type);
}

long long int	get_param_reg(struct user *info, int parameter)
{
  long long int	regs[6];

  memset(regs, 0, sizeof(regs));
  regs[0] = info->regs.rdi;
  regs[1] = info->regs.rsi;
  regs[2] = info->regs.rdx;
  regs[3] = info->regs.rcx;
  regs[4] = info->regs.r8;
  regs[5] = info->regs.r9;
  if (parameter > 5 || parameter < 0)
    return (0);
  return (regs[parameter]);
}

void	add_arguments(t_syscall_info *call, struct user *info,
                    char *res, int sizem)
{
  char	argtmp[BUFSIZ];
  int	i;
  int	pos;
  char	*fmt;
  pid_t	pid;

  i = 0;
  pos = 0;
  pid = info->regs.rax;
  fmt = "%s";
  while (call->args[i])
    {
      fill_with_type_value(call->args[i], get_param_reg(info, i), argtmp, pid);
      if ((pos += snprintf(&(res[pos]), sizem - pos, fmt, argtmp)) >= sizem)
        return ;
      fmt = ", %s";
      i++;
    }
  snprintf(&(res[pos]), sizem - pos, ")");
}

void	print_syscall(struct user *infos, struct user *ret, pid_t pid)
{
  int	sysnb;
  char	rettmp[BUFSIZ];
  char	restmp[2 * BUFSIZ];
  int	i;

  i = 0;
  sysnb = infos->regs.rax;
  infos->regs.rax = pid;
  if ((sysnb < (int)(sizeof(g_syscall_x86_x64) / sizeof(t_syscall_info)))
      && (sysnb >= 0))
    {
      if ((i = snprintf(restmp, sizeof(restmp), "%s(",
                        g_syscall_x86_x64[sysnb].name)) < (int)sizeof(restmp))
        add_arguments(&(g_syscall_x86_x64[sysnb]), infos,
                      &(restmp[i]), sizeof(restmp) - i);
      if (ret == NULL)
        strcpy(rettmp, "?");
      else
        fill_with_type_value(g_syscall_x86_x64[sysnb].ret,
                             ret->regs.rax, rettmp, pid);
      handle_error_case(rettmp, ret ? ret->regs.rax : 0);
      dprintf(STDERR_FILENO, "%-39s = %s\n", restmp, rettmp);
    }
  else
    dprintf(STDERR_FILENO, "Unknown syscall %d\n", sysnb);
}
