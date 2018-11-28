CC=gcc
OBJS=baseball.o baseball_hard.o
LIB=libbaseballs.a libbaseballhard.a

$(LIB): $(OBJS)
	ar rv $(LIB) $(OBJS)

%.o:%.c
	$(CC) -g -c -I../include $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
