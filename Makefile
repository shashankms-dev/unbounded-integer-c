CC=gcc
CFLAGS=-Wall -O2
TARGET=ubint

$(TARGET): main.c ub_int.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -f $(TARGET)
