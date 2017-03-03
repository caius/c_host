FLAGS  = -std=gnu99 -Iinclude
CFLAGS = -fPIC -Wall -Wextra -march=native -ggdb3

.PHONY: default
default: host plugin.so

plugin.so: plugin.o
	$(CC) $(FLAGS) $(CFLAGS) -shared -o plugin.so plugin.o

clean:
	rm -rf *.o *.so host
