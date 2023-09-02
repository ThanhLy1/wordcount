###############################################################################
###               University of Hawaii, College of Engineering
###               Lab 3 - wc - SRE - Spring 2023
###
### Build and test a Word Counting program
###
### @see     https://www.gnu.org/software/make/manual/make.html
###
### @file    Makefile
### @author Thanh Ly 
###############################################################################


TARGET = wc

all: $(TARGET)

CC     = gcc
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)

wc: wc.c
	$(CC) $(CFLAGS) -o $(TARGET) wc.c

c-vector.c: library/vec.c
	$(CC) $(CFLAGS) -o $(TARGET) vec.c

test: wc
	./wc /etc/passwd

clean:
	rm -f $(TARGET) *.o
