CC=gcc
EXE=main
OBJS=main.o

.PHONY: clean

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -L../lib -lbaseballs

%.o: %.c
	$(CC) -g -c -I../include $< -o $@

clean:
	rm $(OBJS) $(EXE)
