CC=gcc
LIBS=gtk4
LFLAGS=$$(pkg-config --cflags $(LIBS))
CFLAGS=$$(pkg-config --libs $(LIBS))
PROGRAM_NAME=program

all:
	$(CC) gktExample.c -o $(PROGRAM_NAME) $(LFLAGS) $(CFLAGS) -g

run:
	./$(PROGRAM_NAME)

clean:
	rm $(PROGRAM_NAME)