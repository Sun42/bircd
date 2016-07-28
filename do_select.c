/*
** do_select.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:12:28 2007 sebastien benoiT
** Last update Tue Apr 17 09:15:18 2007 sebastien benoiT
*/

#include "bircd.h"

void	do_select(t_env *e)
{
  e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
}
