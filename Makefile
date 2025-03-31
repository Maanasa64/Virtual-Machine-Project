CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = src/vm.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = vm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)