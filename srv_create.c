/*
** srv_create.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:37:38 2007 sebastien benoiT
** Last update Tue Apr 17 08:28:22 2007 sebastien benoiT
*/

#include "bircd.h"

void			srv_create(t_env *e, int port)
{
  int			s;
  struct sockaddr_in	sin;
  struct protoent	*pe;
  
  pe = (struct protoent*)X(NULL, getprotobyname("tcp"), "getprotobyname");
  s = X(-1, socket(PF_INET, SOCK_STREAM, pe->p_proto), "socket");
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(port);
  X(-1, bind(s, (struct sockaddr*)&sin, sizeof(sin)), "bind");
  X(-1, listen(s, 42), "listen");
  e->fds[s].type = FD_SERV;
  e->fds[s].fct_read = srv_accept;
}
