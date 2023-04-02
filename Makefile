CC=gcc
CFLAGS=-Wall -Wextra -g -lm
EXEC=ubint

$(EXEC): *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o
	rm -f $(EXEC)
