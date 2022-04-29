#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "blast-core.h"
#include "blast-generators.h"

void test_file(){
    FILE *fasta = fopen("DNACervisiaeSaccharomyces.txt.oneline", "r");

    fseek(fasta, 0, SEEK_END);
    int filesize = ftell(fasta);
    fseek(fasta, 0, SEEK_SET);

    char *file_contents = calloc(filesize+1, sizeof(char));
    fgets(file_contents, filesize, fasta);
    //puts(file_contents);
    best_match b = get_blast_matches(file_contents, "acacgctacaggcctataactt");
    printf("pos: %d, score: %d\n",b.pos, b.score);

    free(file_contents);
    fclose(fasta);

}

void test_matches(){
    const char match1[] = "00100100010011011100";
    const char match2[] = "01111000000110111100000011";

    best_match res1 = process_matches(match1);
    best_match res2 = process_matches(match2);
    puts(match1);
    printf("pos: %d, score: %d\n", res1.pos, res1.score);
    puts(match2);
    printf("pos: %d, score: %d\n", res2.pos, res2.score);
}

int main(){
    test_matches();
    test_file();
}

