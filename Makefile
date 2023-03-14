CC = gcc
CFLAGS = -Wall -Werror -lpthread

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %, $(SRC))

$(info $(SRC))

.PHONY: all clean

all: $(OBJ)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ)