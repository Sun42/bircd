/*
** clean_fd.c for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 08:41:14 2007 sebastien benoiT
** Last update Tue Apr 17 08:42:35 2007 sebastien benoiT
*/

#include "bircd.h"

void	clean_fd(t_fd *fd)
{
  fd->type = FD_FREE;
  fd->fct_read = NULL;
  fd->fct_write = NULL;
  fd->buf_read[0] = '\0';
  fd->buf_write[0] = '\0';
}
