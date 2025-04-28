CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/main.c src/student.c src/file_manager.c
OBJ = $(SRC:.c=.o)
TARGET = C

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) src/*.o

.PHONY: all clean
