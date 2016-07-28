/*
** get_opt.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:23:49 2007 sebastien benoiT
** Last update Tue Apr 17 09:06:47 2007 sebastien benoiT
*/

#include "bircd.h"

void	get_opt(t_env *e, int ac, char **av)
{
  if (ac != 2)
    {
      fprintf(stderr, USAGE, av[0]);
      exit(1);
    }
  e->port = atoi(av[1]);
}

