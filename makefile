CC = gcc
CFLAGS := -m64 

INC = -I"C:\Users\User\Desktop\ctest02"
LIBPATH = -L"C:\Users\User\Desktop\ctest02"
LIBS := -lmod1 -lmod2

PHONY:all
all:
	$(CC) $(INC) main.c $(LIBPATH) $(LIBS) -o main 

PHONY:mod1
mod1:
	$(CC) -fPIC -c mod1.c -o mod1.o
	$(CC) -shared mod1.o -o libmod1.so

PHONY:mod2
mod2:
	$(CC) -fPIC -c mod2.c -o mod2.o
	$(CC) -shared mod2.o -o libmod2.so

clean:
	rm *.exe *.o *.so