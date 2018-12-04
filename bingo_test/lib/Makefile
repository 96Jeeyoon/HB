CC=gcc
OBJS=check_bingo.o del_num.o init_bingo.o input_num.o menu.o myAlloc.o one.o two.o same_num.o
LIB=libbingo.a

$(LIB): $(OBJS)
	ar rv $(LIB) $(OBJS)

%.o:%.c
	$(CC) -g -c -I../include $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
