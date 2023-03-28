CC=gcc
CFLAGS=-Wall -Wextra -g -lm
TARGET=ubint

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(TARGET)
