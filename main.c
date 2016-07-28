/*
** main.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:21:51 2007 sebastien benoiT
** Last update Tue Apr 17 07:26:53 2007 sebastien benoiT
*/

#include "bircd.h"

int	main(int ac, char **av)
{
  t_env	e;

  init_env(&e);
  get_opt(&e, ac, av);
  srv_create(&e, e.port);
  main_loop(&e);
  return (0);
}
