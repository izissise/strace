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

typedef struct	s_type_map
{
  char		*type;
  char		*conv;
}		t_type_map;

t_type_map	g_typemap[] = {
  {"int", "%d"},
  {"char*", "0x%x"},
  {"void*", "0x%x"},
  {"ssize_t", "%u"},
  {"struct pollfd*", NULL}
};

#endif /* !TYPE_MAP_H_INCLUDED */
