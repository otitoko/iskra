CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
SRC= src/main.c src/builtins/echo.c
OBJ = $(SRC:,c=.o)
TARGET = iskra

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
