CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

SRCS = reader.c 
OBJS = $(SRCS:.c=.o)
EXEC = mySA

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)