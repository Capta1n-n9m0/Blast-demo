#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blast-core.h"
#include <limits.h>

int max(const int arr[], int n){
	int res = 0;
	for (int i = 0; i < n; ++i)
		if(arr[i] > res) res = arr[i];
	return res;
}

typedef struct node_{
	int col, row, val;
}node;

typedef struct matrix_{
	int width, height;
	node maximum;
	int **data;
} matrix;

matrix SW_search(const char *data, const char *target){
	matrix res;
	int data_length = strlen(data), target_length = strlen(target);
	res.width = data_length;
	res.height = target_length;
	int **pmatrix = malloc(target_length * sizeof (int *));
	for(int row = 0; row < target_length+1; row++)
		pmatrix[row] = calloc(data_length + 1, sizeof(int));
	int maximum = 0;
	for(int i = 0; i < data_length; i++) pmatrix[0][i] = 0;
	for(int i = 0; i < target_length; i++) pmatrix[i][0] = 0;
	for(int row = 1; row < target_length; row++){
		for(int col = 1; col < data_length; col++){
			int diag = pmatrix[row - 1][col - 1];
			if(data[col] == target[row]) diag += 3; else diag -=3;
			int left = pmatrix[row][col - 1] - 2;
			int up = pmatrix[row - 1][col] - 2;
			pmatrix[row][col] = max((int[]){diag, left, up}, 3);
			if(pmatrix[row][col] > maximum) {
				res.maximum.col = col;
				res.maximum.row = row;
				maximum = pmatrix[row][col];
			}
		}
	}
	res.data = pmatrix;
	res.maximum.val = maximum;
	return res;
}

typedef struct sw_result_{
	char *v1, *v2;
	int score;
}sw_result;

typedef struct linked_node_{
	int length, row, col, value;
	char letter;
	struct linked_node_ *next;
}linked_node;

linked_node *add_to_beginning_of_linked_list(linked_node *list, int row, int col, int value){
	linked_node *res = calloc(1, sizeof(linked_node));
	if(list == NULL) res->length=1; else res->length = list->length + 1;
	res->row = row;
	res->col = col;
	res->value = value;
	res->next = list;
	return res;
}

sw_result sw_backtrack(matrix m, const char *data, const char *target){
	sw_result res;
	res.score = m.maximum.val;
	int row = m.maximum.row, col = m.maximum.col;
	int next_row, next_col;
	int value = m.data[row][col];
	linked_node *path = add_to_beginning_of_linked_list(NULL, row, col, value);
	int diag, left, up;
	while (m.data[row][col]){
		diag = m.data[row-1][col-1];
		left = m.data[row][col-1];
		up = m.data[row-1][col];
		next_row = row-1;
		next_col = col-1;
		if(up > value){
			next_row = row - 1;
			next_col = col;
		}
		if(left > value){
			next_row = row;
			next_col = col-1;
		}
		if(diag > value){
			next_row = row-1;
			next_col = col-1;
		}
		row = next_row;
		col = next_col;
		value = m.data[row][col];
		if(value != 0) path = add_to_beginning_of_linked_list(path, row, col, value);
	}
	linked_node *curr = path;
	res.v1 = calloc(path->length+1, sizeof(char ));
	res.v2 = calloc(path->length+1, sizeof(char ));
	int letter_counter = 0;
	int prev_col = -1, prev_row = -1;
	while (curr){
		row = curr->row;
		col = curr->col;
		if(row == prev_row) res.v1[letter_counter] = '-';
		else res.v1[letter_counter] = target[row];
		if(col == prev_col) res.v2[letter_counter] = '-';
		else res.v2[letter_counter] = data[col];
		prev_col = col;
		prev_row = row;
		letter_counter++;
		curr = curr->next;
	}
	return res;
}

void test_sw_on_file(){
	FILE *pFasta = fopen("DNACervisiaeSaccharomyces.txt.oneline", "r");
	
	fseek(pFasta, 0, SEEK_END);
	int nFilesize = ftell(pFasta);
	fseek(pFasta, 0, SEEK_SET);
	
	char *sFile_contents = calloc(nFilesize + 1, sizeof(char));
	fgets(sFile_contents, nFilesize, pFasta);
	
	char target[] = "acacgctacaggcctataactt";
	
	matrix matrix1 = SW_search(sFile_contents, target);
	
	printf("(row = %d, col = %d) = %d\n", matrix1.maximum.row, matrix1.maximum.col, matrix1.maximum.val);
	
	sw_result res = sw_backtrack(matrix1, sFile_contents, target);
	
	printf("%s\n%s\n", res.v1, res.v2);
	
	
	
	
}

void test_sw(){
	const char *dna = "TGTTACGG";
	const char *searchedPart = "GGTTGACTA";
	matrix res = SW_search(dna, searchedPart);
	for(int row = 0; row < res.height; row++){
		for (int col = 0; col < res.width; ++col) {
			printf("%3d ", res.data[row][col]);
		}
		puts("");
	}
	printf("(col=%d, row=%d) = %d\n", res.maximum.col, res.maximum.row, res.maximum.val);
	sw_result full = sw_backtrack(res, dna, searchedPart);
	printf("%s\n%s\n", full.v1, full.v2);
	
	
}

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
//	test_matches();
//	test_file();
	//test_sw();
	test_sw_on_file();
}

