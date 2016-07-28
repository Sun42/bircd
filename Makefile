##
## Makefile for bircd in /u/guest/sb/c/bircd
## 
## Made by sebastien benoiT
## Login   <sb@epita.fr>
## 
## Started on  Tue Apr 17 07:32:09 2007 sebastien benoiT
## Last update Tue Apr 17 09:16:15 2007 sebastien benoiT
##

SRCS =	main.c init_env.c clean_fd.c get_opt.c x.c main_loop.c \
	init_fd.c do_select.c check_fd.c \
	srv_create.c srv_accept.c \
	client_read.c client_write.c

OBJS = ${SRCS:.c=.o}

NAME = bircd

CFLAGS = -I. -g3

LDFLAGS = 

CC = cc

RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

clean:
		${RM} ${OBJS} *~ #*#

fclean:		clean
		${RM} ${NAME}

re:		fclean all
