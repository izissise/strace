/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
** 
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
** 
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Thu May  1 18:55:57 2014 Harold Fritsch
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ptrace_exec(char *program_name)
{
  printf("ptrace_exec(%s)\n", program_name);;
}

void	ptrace_attach(int pid)
{
  if (!pid)
    {
      fprintf(stderr, "ERROR : invalid PID\n");
      return ;
    }
  printf("ptrace_attach(%d)\n", pid);;
}

int	main(int ac, char **av)
{
  if (ac == 2)
    ptrace_exec(av[1]);
  else if (ac == 3 && strcmp("-p", av[1]))
    ptrace_attach(atoi(av[2]));
  else
    fprintf(stderr, "USAGE : %s [-p PID] | program name\n", av[0]);
  return (0);
}
