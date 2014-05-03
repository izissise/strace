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
