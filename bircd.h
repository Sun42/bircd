/*
** bircd.h for bircd in /u/guest/sb/c/bircd
** 
** Made by sebastien benoiT
** Login   <sb@epita.fr>
** 
** Started on  Tue Apr 17 07:24:18 2007 sebastien benoiT
** Last update Tue Apr 17 09:05:45 2007 sebastien benoiT
*/

#ifndef BIRCD_H_
# define BIRCD_H_

# include <stdio.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <errno.h>

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2

# define BUF_SIZE	4096

# define X(err,res,str)	(x(err,res,str,__FILE__,__LINE__))
# define MAX(a,b)	((a > b) ? a : b)

# define USAGE		"Usage: %s port\n"

typedef struct	s_fd
{
  int	type;
  void	(*fct_read)();
  void	(*fct_write)();
  char	buf_read[BUF_SIZE + 1];
  char	buf_write[BUF_SIZE + 1];
}		t_fd;

typedef struct	s_env
{
  t_fd		*fds;
  int		port;
  int		maxfd;
  int		max;
  int		r;
  fd_set	fd_read;
  fd_set	fd_write;
}		t_env;

void	srv_accept(t_env *e, int s);
void	client_read(t_env *e, int cs);
void	client_write(t_env *e, int cs);

#endif /* !BIRCD_H_ */
