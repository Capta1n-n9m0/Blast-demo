#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "blast-core.h"
#include "blast-generators.h"


int main(int argc, char **argv){
    srand(time(NULL));
    assert(argc > 2);
    FILE *fasta = fopen(argv[1], "r");

    fseek(fasta, 0, SEEK_END);
    int filesize = ftell(fasta);
    fseek(fasta, 0, SEEK_SET);

    char *file_contents = calloc(filesize+1, sizeof(char));
    fgets(file_contents, filesize, fasta);
    //puts(file_contents);
    best_match b = get_blast_matches(file_contents, argv[2]);
    printf("pos: %d, score: %d\n",b.pos, b.score);

    free(file_contents);
    fclose(fasta);
}

