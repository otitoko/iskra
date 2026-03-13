CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
SRC= src/main.c src/builtins/echo.c src/builtins/exec_cmd.c src/builtins/cd.c src/parsing/parsing.c src/input/input.c src/builtins/builtins.c src/misc/error_related.c
OBJ = $(SRC:,c=.o)
TARGET = iskra

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
