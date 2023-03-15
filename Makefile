CC = gcc
CFLAGS = -Wall -Werror -MD
LDFLAGS = -pthread

SRCS = $(wildcard *.c)
BINS = $(SRCS:%.c=%)

.PHONY: all clean

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm $(BINS) $(BINS:%=%.d)

-include $(SRCS:.c=.d)

