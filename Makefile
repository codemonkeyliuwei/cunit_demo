.PHONY:clean

CC=gcc
CXX=g++
INCLUDE=-I/usr/local/include/CUnit
LIB_PATH=-L/usr/local/lib
LIB=-lcunit

CFLAGS=-g

#DFLAGS=-DCUNIT_CONSOLE
DFLAGS=-DCUNIT_AUTOMATED

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)
UT_NAME=ut_test

all: $(OBJ)
	$(CXX) $^ -o $(UT_NAME) $(LIB_PATH) $(LIB)
	
%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $^
	
clean:
	-rm -rf $(OBJ) $(UT_NAME) 
