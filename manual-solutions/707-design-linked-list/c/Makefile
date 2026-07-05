### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lcriterion

###
CFLAGS  = -std=c11
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

.PHONY: all
all: test

.PHONY: test
test: test.out
	@./test.out

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

test.out: ./solution.test.c ./solution.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) solution.c solution.test.c -o test.out $(LIBS)
