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

void	trace_void(UNSEDP long long int reg, char res[BUFSIZ],
                 UNSEDP t_strace *trace)
{
  snprintf(res, BUFSIZ, "?");
}

void	trace_size_t(long long int reg, char res[BUFSIZ], UNSEDP t_strace *trace)
{
  snprintf(res, BUFSIZ, "%lld", reg);
}