CC=gcc
CFLAGS=-Wall -Wextra -g -lm
SRC_DIR=src
INSTALL_DIR=/usr/lib64
EXEC=ubint
LIB=libubint.so

all: $(LIB) $(EXEC)

$(LIB): $(SRC_DIR)/*.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -lc -o $@

$(EXEC): *.c
	$(CC) $(CFLAGS) -L. -lubint $^ -o $@

clean:
	rm -f *.o *.so
	rm -f $(EXEC)

install:
	cp $(LIB) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(LIB)
