CC      := gcc
CXX     := g++
CFLAGS  := -O3 -Wall -pthread 

SRC 	:= ./
SRCS    := $(shell find $(SRC) -name '*.c')

OBJS    := $(SRCS:%.c=%.o)

BIN 	:= ./
LDFLAGS := 
LDLIBS	:= -lm
MKDIR   := mkdir
RMDIR   := rmdir

.PHONY: all
all:$(OBJS) | $(BIN)
	$(CC) -o $(BIN)/main $^ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo make target [$@] is complete

.PHONY: clean
clean:
	-rm -f $(BIN)/main $(OBJS)



