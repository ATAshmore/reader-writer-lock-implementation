readerwriter: main.c readerwriter.c newthread.h
	gcc main.c readerwriter.c -o rwmain -lpthread