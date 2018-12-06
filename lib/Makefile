CC=gcc OBJS=baseball_easy.o baseball_hard.o check_bingo.o del_num.o 
init_bingo.o input_num.o menu.o myAlloc.o one.o two.o same_num.o win.o 
LIB=libHB.a

$(LIB): $(OBJS)
	ar rv $(LIB) $(OBJS)

%.o:%.c
	$(CC) -g -c -I../include $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
