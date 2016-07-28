/*
** init_fd.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:06:03 2007 sebastien benoiT
** Last update Tue Apr 17 09:15:30 2007 sebastien benoiT
*/

#include "bircd.h"

void	init_fd(t_env *e)
{
  int	i;

  i = 0;
  e->max = 0;
  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  while (i < e->maxfd)
    {
      if (e->fds[i].type != FD_FREE)
	{
	  FD_SET(i, &e->fd_read);
	  if (strlen(e->fds[i].buf_write) > 0)
	    {
	      FD_SET(i, &e->fd_write);
	    }
	  e->max = MAX(e->max, i);
	}
      i++;
    }
}
