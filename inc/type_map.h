/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#ifndef TYPE_MAP_H_INCLUDED
# define TYPE_MAP_H_INCLUDED

# include "strace.h"

t_type_map	g_typemap[] = {
  {"int", &trace_int},
  {"unsigned int", &trace_uint},
  {"char*", &trace_chartoile},
  {"void*", &trace_ptrtoile},
  {"void*", &trace_void},
  {"size_t", &trace_size_t},
  {"ssize_t", &trace_ssizet}
};

#endif /* !TYPE_MAP_H_INCLUDED */
