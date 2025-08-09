# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Executable name
TARGET = main_singlyLinkedList

# Source and object files
SRCS = main_singlyLinkedList.c singlyLinkedList.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	del /Q *.o *.exe   # For Windows
	# rm -f *.o $(TARGET)  # For Linux/macOS

# Run the program (optional)
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run explain me everything 
