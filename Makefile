CC	=	gcc

CFLAGS	=	-g3 -Wall

SRC_FILES	=	src

SRCS	=	$(SRC_FILES)/tcp_client.c \
			$(SRC_FILES)/tcp_server.c

BINARY	=	sockets

all:	$(BINARY)

$(BINARY):	${SRCS}
	${CC} ${CFLAGS} ${SRC_FILES}/tcp_client.c -o tcp_client
	${CC} ${CFLAGS} ${SRC_FILES}/tcp_server.c -o tcp_server

%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS) tcp_client tcp_server
	rm -f $(SRC_FILES)/*~ $(SRC_FILES)/*.o
	rm -f *.gcno *.gcda *.vgcore

re:	clean all

submit:
	@git status -s
	make clean

.PHONY:	clean all re
