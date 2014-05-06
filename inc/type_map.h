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
  void		(*conv)(long long int reg, char res[BUFSIZ], pid_t pid);
}		t_type_map;

void	trace_int(long long int reg, char res[BUFSIZ], pid_t pid);
void	trace_uint(long long int reg, char res[BUFSIZ], pid_t pid);
void	trace_chartoile(long long int reg, char res[BUFSIZ], pid_t pid);
void	trace_ptrtoile(long long int reg, char res[BUFSIZ], pid_t pid);
void	trace_ssizet(long long int reg, char res[BUFSIZ], pid_t pid);

t_type_map	g_typemap[] = {
  {"int", &trace_int},
  {"unsigned int", &trace_uint},
  {"char*", &trace_chartoile},
  {"void*", &trace_ptrtoile},
  {"ssize_t", &trace_ssizet}
};

#endif /* !TYPE_MAP_H_INCLUDED */
