ARGS			=
EXECUTABLE		=main
CC				=gcc
CFLAGS			=-Wall -Werror --pedantic -std=c2x -g
LDFLAGS			=
SOURCES			=$(wildcard *.c)
HEADERS			=$(wildcard *.h)
OBJECTS			=$(SOURCES:.c=.o)

all: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full -v ./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(EXECUTABLE)

.PHONY: clean
clean:
	-rm $(OBJECTS)

# prepare: $(SOURCES) $(HEADERS)
# 	python3 prepare_file.py $(SOURCES) $(HEADERS) makefile test.txt ex3test.txt
