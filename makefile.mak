#makefile
CC = gcc
WARNINGS = -Wall

all: ByteFunctions.dll

ByteFunctions.dll: ByteFunctions.o
	$(CC) -shared -o ByteFunctions.dll ByteFunctions.o -Wl,--out-implib,libmessage.a
	
ByteFunctions.o: ByteFunctions.c ByteFunctions.h
	$(CC) -c -DBUILD_DLL ByteFunctions.c
	
clean:
	rm -rf *o ByteFunctions.dll
