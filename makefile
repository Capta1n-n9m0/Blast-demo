ARGS			=DNACervisiaeSaccharomyces.txt.oneline acacgctacaggcctataactt
EXECUTABLE		=main
CC				=gcc
CFLAGS			=-Wall -Werror --pedantic -std=c2x -g
LDFLAGS			=
SOURCES			=$(wildcard *.c)
HEADERS			=$(wildcard *.h)
OBJECTS			=$(SOURCES:.c=.o)

all: $(EXECUTABLE) $(parse)
	$(parse)
	./$(EXECUTABLE) $(ARGS)

build: $(EXECUTABLE)

parse: parse_fasta.py DNACervisiaeSaccharomyces.txt
	./parse_fasta.py DNACervisiaeSaccharomyces.txt

valgrind: $(EXECUTABLE)
	valgrind --leak-check=full -v ./$(EXECUTABLE) $(ARGS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(EXECUTABLE)

.PHONY: clean
clean:
	-rm $(OBJECTS)

# prepare: $(SOURCES) $(HEADERS)
# 	python3 prepare_file.py $(SOURCES) $(HEADERS) makefile test.txt ex3test.txt
