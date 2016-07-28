/*
** main_loop.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:55:10 2007 sebastien benoiT
** Last update Tue Apr 17 08:05:49 2007 sebastien benoiT
*/

#include "bircd.h"

void	main_loop(t_env *e)
{
  while (1)
    {
      init_fd(e);
      do_select(e);
      check_fd(e);
    }
}
