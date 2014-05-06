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
#include "syscall_x86.h"
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
  snprintf(res, BUFSIZ, "%s", type);
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

void	format_syscall(struct user *infos, int sysnb,
                     t_syscall_info *systable, char restmp[2 * BUFSIZ])
{
  int	i;

  i = 0;
  if ((i = snprintf(restmp, 2 * BUFSIZ, "%s(",
                    systable[sysnb].name)) < 2 * BUFSIZ)
    {
      add_arguments(&(systable[sysnb]), infos,
                    &(restmp[i]), 2 * BUFSIZ - i);
    }
}

void			print_syscall(struct user *infos, struct user *ret,
                        pid_t pid, int bit)
{
  char			rettmp[BUFSIZ];
  char			restmp[2 * BUFSIZ];
  int			sysnb;
  t_syscall_info	*systable;
  int			tabsize;

  systable = bit ? g_syscall_x86_x64 : g_syscall_x86;
  tabsize = (bit ? sizeof(g_syscall_x86_x64) : sizeof(g_syscall_x86))
            / sizeof(t_syscall_info);
  sysnb = infos->regs.rax;
  infos->regs.rax = pid;
  if ((sysnb < tabsize) && (sysnb >= 0))
    {
      format_syscall(infos, sysnb, systable, restmp);
      if (ret == NULL)
        strcpy(rettmp, "?");
      else
        fill_with_type_value(systable[sysnb].ret,
                             ret->regs.rax, rettmp, pid);
      handle_error_case(rettmp, ret ? ret->regs.rax : 0);
      dprintf(STDERR_FILENO, "%-39s = %s\n", restmp, rettmp);
    }
  else
    dprintf(STDERR_FILENO, "Unknown syscall %d\n", sysnb);
}
