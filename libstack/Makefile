CC = gcc
MKDIR = mkdir -p
RM = rm -rf
AR = ar rcs $(LIBNAME) $(OBJECTS)
CFLAGS = -g -Wall -Iinclude
FILES = stack.c

OBJECTS = $(FILES:.c=.o)
LIBNAME = libstack.a
EXENAME = test.o

all: $(LIBNAME)

test: $(EXENAME)

$(LIBNAME): $(OBJECTS)
	$(AR)
	$(RM) $(OBJECTS)

$(OBJECTS): %.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

# tries to make test.o twice?
$(EXENAME): src/main.c $(LIBNAME)
	$(CC) -static $(CFLAGS) $< -L. -lstack -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIBNAME)
	$(RM) $(EXENAME)