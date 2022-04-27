#include "blast-core.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SEGMENTS_PER_LINE 20

void print_segment(segment s){
    if(s.m1) printf("x"); else printf("o");
    if(s.m2) printf("x"); else printf("o");
    if(s.m3) printf("x"); else printf("o");
    if(s.m4) printf("x"); else printf("o");
    if(s.m5) printf("x"); else printf("o");
    if(s.m6) printf("x"); else printf("o");
    if(s.m7) printf("x"); else printf("o");
    if(s.m8) printf("x"); else printf("o");
}

void print_segments(segment *s, int length){
    int segs = 0;
    for(int i = 0; i < length; i++){
        print_segment(s[i]);
        segs++;
        if (segs == SEGMENTS_PER_LINE){
            puts("");
            segs = 0;
        }
    }
    puts("");
}

char *convert_segments_to_string(segment *s, int length){
    char *res = calloc(length*8 + 1, sizeof(char ));
    int c = 0;
    for(int i = 0; i < length; i++){
        if(s[i].m1) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m2) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m3) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m4) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m5) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m6) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m7) res[c++] = 'x'; else res[c++] = 'o';
        if(s[i].m8) res[c++] = 'x'; else res[c++] = 'o';
    }
    return res;
}

best_match get_the_best_match(const char *sequence){
    best_match res = {0};
    int max = -1, sum = 0;
    int best_pos = 0, start_pos = 0;
    int length = strlen(sequence);
    for(int i = 0 ; i < length; i++){
        if(sequence[i] == 'x') sum++; else sum--;
        if(max < sum) {
            max = sum;
            best_pos = start_pos;
        }
        if(sum < 0) {
            sum = 0;
            start_pos = i;
        }
    }
    res.score = max;
    res.pos = best_pos;
    return res;
}

