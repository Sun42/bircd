/*
** client_read.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:50:03 2007 sebastien benoiT
** Last update Tue Apr 17 09:13:59 2007 sebastien benoiT
*/

#include "bircd.h"

void	client_read(t_env *e, int cs)
{
  int	r;
  int	i;

  r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
  if (r <= 0)
    {
      close(cs);
      clean_fd(&e->fds[cs]);
      printf("client #%d gone away\n", cs);
    }
  else
    {
      i = 0;
      while (i < e->maxfd)
	{
	  if ((e->fds[i].type == FD_CLIENT) &&
	      (i != cs))
	    send(i, e->fds[cs].buf_read, r, 0);
	  i++;
	}
    }
}
