/*
** srv_accept.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:26:17 2007 sebastien benoiT
** Last update Tue Apr 17 09:14:11 2007 sebastien benoiT
*/

#include "bircd.h"

void			srv_accept(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	csin;
  int			csin_len;

  cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
  printf("New client #%d from %s:%d\n", cs,
	 inet_ntoa(csin.sin_addr.s_addr), ntohs(csin.sin_port));
  clean_fd(&e->fds[cs]);
  e->fds[cs].type = FD_CLIENT;
  e->fds[cs].fct_read = client_read;
  e->fds[cs].fct_write = client_write;
}
