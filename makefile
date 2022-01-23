CC = gcc
CFLAGS := -O3 -Wall

LIBPATH = -L"./lib"
LIBS := -lmod

PHONY:all
all:mod
#	$(CC) $(CFLAGS) main.c ./lib/libmod.so -o main
	$(CC) $(CFLAGS) main.c $(LIBPATH) $(LIBS) -o main 

PHONY:mod1
mod1:
	$(CC) $(CFLAGS) -fPIC -c mod1.c -o mod1.o
	$(CC) $(CFLAGS) -shared mod1.o -o libmod1.so

PHONY:mod2
mod2:
	$(CC) $(CFLAGS) -fPIC -c mod2.c -o mod2.o
	$(CC) $(CFLAGS) -shared mod2.o -o libmod2.so

PHONY:mod
mod:mod1 mod2
	$(CC) $(CFLAGS) -shared mod1.o mod2.o -o ./lib/libmod.so
#	ar rvs ./lib/libmod.o mod1.o mod2.o

clean:
	rm *.o *.so main ./lib/*.so ./lib/*.o
