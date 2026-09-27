# Build the difftest harness: the native functions in src/native/ plus harness.c.
#   make -C tools/difftest            -> tools/difftest/build/harness
#   make -C tools/difftest asan       -> the same with address and undefined-behaviour sanitizers
CC ?= cc
CFLAGS ?= -std=c99 -O1 -g
WARN = -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wno-sign-conversion
NATIVE = ../../src/native
SRCS = harness.c $(NATIVE)/mem.c $(NATIVE)/engine.c $(NATIVE)/layout.c $(NATIVE)/spell_stack.c \
       $(NATIVE)/card_query.c
HDRS = $(NATIVE)/mem.h $(NATIVE)/engine.h

build/harness: $(SRCS) $(HDRS) | build
	$(CC) $(CFLAGS) $(WARN) -o $@ $(SRCS)

asan: $(SRCS) $(HDRS) | build
	$(CC) $(CFLAGS) $(WARN) -fsanitize=address,undefined -fno-omit-frame-pointer -o build/harness-asan $(SRCS)

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: asan clean
