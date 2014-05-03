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

void	fill_with_type_value(char *type, long long int reg,
                           char res[BUFSIZ])
{
  strcpy(res, "efe");
}

long long int	get_reg(struct user *info, int parameter)
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

  i = 0;
  pos = 0;
  fmt = "%s";
  while (call->args[i])
    {
      fill_with_type_value(call->args[i], get_reg(info, i), argtmp);
      if ((pos += snprintf(&(res[pos]), sizem, fmt, argtmp)) >= sizem)
        return ;
      fmt = ", %s";
      i++;
    }
}

void	print_syscall(struct user *infos, struct user *ret)
{
  int	sysnb;
  char	rettmp[BUFSIZ];
  char	restmp[2 * BUFSIZ];
  int	i;

  i = 0;
  sysnb = infos->regs.rax;
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
                             ret->regs.rax, rettmp);
      dprintf(STDERR_FILENO, "%41s = %s\n", restmp, rettmp);
    }
  else
    dprintf(STDERR_FILENO, "Unknow syscall %d", sysnb);
}
