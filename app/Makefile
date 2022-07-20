CC = gcc

CFLAGS = -I./inc/
DEPS = client.h server.h
OBJ = src/main.o src/server.o src/client.o

%o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 
chat: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)	-lpthread

all:

clean:
	rm -rf *.o chat	src/*.o 

install:
	echo "This is make install"
