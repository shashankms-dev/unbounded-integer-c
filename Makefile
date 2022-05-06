CC=gcc
CFLAGS=-Wall -O2
TARGET=ubint

$(TARGET): *.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(TARGET)
