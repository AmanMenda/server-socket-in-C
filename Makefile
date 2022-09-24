CC	=	gcc

CFLAGS	=	-g3 -Wall

SRC_FILES	=	src

SRCS	=	$(wildcard $(SRC_FILES)/*.c)

OBJS	=	$(SRCS:.c=.o)

BINARY	=	sockets

all:	$(BINARY)

$(BINARY):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BINARY)
	rm -f $(SRC_FILES)/*~ $(SRC_FILES)/*.o
	rm -f *.gcno *.gcda *.vgcore

re:	clean all

submit:
	@git status -s
	make clean

.PHONY:	clean all re
