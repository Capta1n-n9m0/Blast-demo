#include <stdio.h>
#include <stdlib.h>
#include "blast-core.h"

void test_file() {
	FILE *pFasta = fopen("DNACervisiaeSaccharomyces.txt.oneline", "r");
	
	fseek(pFasta, 0, SEEK_END);
	int nFilesize = ftell(pFasta);
	fseek(pFasta, 0, SEEK_SET);
	
	char *sFile_contents = calloc(nFilesize + 1, sizeof(char));
	fgets(sFile_contents, nFilesize, pFasta);
	
	best_match b = get_blast_matches(sFile_contents, "acacgctacaggcctataactt");
	printf("nPos: %d, nScore: %d\n", b.nPos, b.nScore);
	
	free(sFile_contents);
	fclose(pFasta);
	
}

void test_matches() {
	const char sMatch1[] = "00100100010011011100";
	const char sMatch2[] = "01111000000110111100000011";
	
	best_match res1 = process_matches(sMatch1);
	best_match res2 = process_matches(sMatch2);
	puts(sMatch1);
	printf("nPos: %d, nScore: %d\n", res1.nPos, res1.nScore);
	puts(sMatch2);
	printf("nPos: %d, nScore: %d\n", res2.nPos, res2.nScore);
}

int main() {
	test_matches();
	test_file();
}

