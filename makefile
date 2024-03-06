CC=gcc
LIBS=gtk4
LFLAGS=$$(pkg-config --cflags $(LIBS))
CFLAGS=$$(pkg-config --libs $(LIBS))
PROGRAM_NAME=program

all:
	$(CC) GUI/gktExample.c -o $(PROGRAM_NAME) $(LFLAGS) $(CFLAGS)

run:
	./$(PROGRAM_NAME)

clean:
	rm $(PROGRAM_NAME)