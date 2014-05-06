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

void	trace_int(long long int reg, char res[BUFSIZ], UNSEDP pid_t pid)
{
  snprintf(res, BUFSIZ, "%d", (int)reg);
}

void	trace_uint(long long int reg, char res[BUFSIZ], UNSEDP pid_t pid)
{
  snprintf(res, BUFSIZ, "%u", (unsigned int)reg);
}

void	trace_chartoile(long long int reg, char res[BUFSIZ], UNSEDP pid_t pid)
{
  snprintf(res, BUFSIZ, "0x%lx", (long int)reg);
}

void	trace_ptrtoile(long long int reg, char res[BUFSIZ], UNSEDP pid_t pid)
{
  snprintf(res, BUFSIZ, "0x%lx", (long int)reg);
}

void	trace_ssizet(long long int reg, char res[BUFSIZ], UNSEDP pid_t pid)
{
  snprintf(res, BUFSIZ, "%ld", (ssize_t)reg);
}
