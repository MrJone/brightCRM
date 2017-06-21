CFLAGS=`pkg-config --cflags gtk+-3.0`
CFLAGS+=-I`pwd`/include
LIBS=`pkg-config --libs gtk+-3.0`
CC=g++

OUTPUT=bcrm

all: main.o signals.o
	$(CC) main.o signals.o -o $(OUTPUT) $(CFLAGS) $(LIBS)

main.o:
	$(CC) main.cpp -c $(CFLAGS) $(LIBS)

signals.o:
	$(CC) signals.cpp -c $(CFLAGS) $(LIBS)

clean:
	rm -rf ./*.o
