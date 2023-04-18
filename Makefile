ifdef OS
   RM = del 
else
   ifeq ($(shell uname), Linux)
      RM = rm
   endif
endif

CC = g++
CFLAGS = -O3 -std=c++17

all: main.o file_functions.o mylib.o
	$(CC) $(CFLAGS) main.o file_functions.o mylib.o -o run

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

file_functions.o: file_functions.cpp file_functions.h
	$(CC) $(CFLAGS) -c file_functions.cpp
	
mylib.o: mylib.cpp mylib.h
	$(CC) $(CFLAGS) -c mylib.cpp

clean:
	$(RM) *.o run