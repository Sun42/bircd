/*
** check_fd.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:15:19 2007 sebastien benoiT
** Last update Tue Apr 17 08:39:35 2007 sebastien benoiT
*/

#include "bircd.h"

void	check_fd(t_env *e)
{
  int	i;

  i = 0;
  while ((i < e->maxfd) && (e->r > 0))
    {
      if (FD_ISSET(i, &e->fd_read))
	e->fds[i].fct_read(e, i);
      if (FD_ISSET(i, &e->fd_write))
	e->fds[i].fct_write(e, i);
      if (FD_ISSET(i, &e->fd_read) ||
	  FD_ISSET(i, &e->fd_write))
	e->r--;
      i++;
    }
}
