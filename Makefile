CC ?= cc
CFLAGS ?= -std=c17 -O2 -Wall -Wextra -Wpedantic

SOURCES := $(wildcard solutions/*.c)
PROGRAMS := $(patsubst solutions/%.c,bin/%,$(SOURCES))

.PHONY: all clean
all: $(PROGRAMS)

bin/%: solutions/%.c | bin
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LDLIBS)

bin:
	mkdir -p $@

clean:
	$(RM) -r bin
