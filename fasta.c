#include "fasta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int if_string_contains_char(const char *data, const char target){
    int len = strlen(data);
    for(int i = 0; i < len; i++){
        if(data[i] == target) return i;
    }
    return -1;
}

static int if_string_contains_string(const char *data, const char *target){
    int data_len = strlen(data);
    int pos = 0;
    for(int i = 0; i < data_len; i++){
        if(!target[pos]) return pos;
        if(data[i] == target[pos]) pos++; else pos = 0;
    }
    return -1;
}

char **split_string_by_separator(char *string, char sep){

//FIXME: this code is not functional

    char **res;
    int len = strlen(string), n = 0, c = 0;
    res = calloc(1, sizeof(char *));
    for(int i = 0; i < len; i++){
        if(string[i] == sep){
            c = 0;
            n++;
            res = realloc(res, n+1);
        } else res[n][c++] = string[i];
    }



    return res;
}

char *read_fasta_file(const char *filename){
    char *line, start_read = 0;
    size_t read, len;
    FILE *f = fopen(filename, "r");
    do{
        getline(&line, &len, f);
        if(if_string_contains_string(line, "ORIGIN") != -1) start_read = 1;
        if(start_read){

        }
    } while (line[0] == '/' && line[1] == '/');






    free(line);
    fclose(f);
}











