C = gcc
CFLAGS = -I. -fPIC
all: $(patsubst %.c, %.o, $(wildcard *.c))
%.out: %.c Makefile	$(CC) -c $(CFLAGS) $< -o $@ -lm
clean:
	rm *.o
