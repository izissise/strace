/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "strace.h"

int			check_if_folder(char *file)
{
  struct stat	s;

  if (stat(file, &s) == -1)
    return (-1);
  else if ((s.st_mode & 0170000) == 0040000)
    return (1);
  return (0);
}

/*
** Return the full path of a command , return the command if didn't find it
** for trying to execute it from the current directory
*/

char	*exec_full_path(char *exec, char **paths)
{
  char	*fpaths;
  int	len;

  fpaths = NULL;
  while ((exec != NULL) && (paths != NULL) && (paths[0] != NULL))
    {
      len = (exec ? strlen(exec) : 0) + (paths[0] ? strlen(paths[0]) : 0) + 2;
      if ((fpaths = malloc(sizeof(char) * len)) == NULL)
        return (exec ? strdup(exec) : NULL);
      snprintf(fpaths, len, "%s/%s", paths[0], exec);
      if ((access(fpaths, F_OK) == 0) && (access(fpaths, X_OK) == 0)
          && (check_if_folder(fpaths) == 0))
        return (fpaths);
      free(fpaths);
      paths = &paths[1];
    }
  return (exec ? strdup(exec) : NULL);
}
