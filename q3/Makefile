CC = gcc
CFLAGS = -Wall -Wextra -g

# source files
SRCS = pmath.c main.c
# header files if they are used for dependency checking
HDRS = pmath.h
# Derive object files from source files
OBJS = $(SRCS:.c=.o)

# Specify the target executable name
TARGET = program

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile object files.
# This assumes each .c file depends on some header files,
# you can adjust it according to your project's actual dependencies.
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean the build
clean:
	rm -f $(TARGET) $(OBJS)