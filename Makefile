CC=gcc
CFLAGS=-Wall -Wextra -g -lm
EXEC=ubint
LIB=libubint.so

all: $(LIB) $(EXEC)

$(LIB): ubint.h ub*.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -lc -o $@

$(EXEC): main.c
	$(CC) $(CFLAGS) -L. -lubint $^ -o $@

clean:
	rm -f *.o *.so
	rm -f $(EXEC)

install:
	cp $(LIB) /lib64
