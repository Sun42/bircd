/*
** init_env.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:27:03 2007 sebastien benoiT
** Last update Tue Apr 17 08:42:49 2007 sebastien benoiT
*/

#include "bircd.h"

void		init_env(t_env *e)
{
  int		i;
  struct rlimit	rlp;

  X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
  e->maxfd = rlp.rlim_cur;
  e->fds = (t_fd*)X(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
  i = 0;
  while (i < e->maxfd)
    {
      clean_fd(&e->fds[i]);
      i++;
    }
}
