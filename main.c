#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef enum match_{
    o, x
}match;

typedef struct segment_{
    match m1: 1;
    match m2: 1;
    match m3: 1;
    match m4: 1;
    match m5: 1;
    match m6: 1;
    match m7: 1;
    match m8: 1;
}segment;

segment *generate_segments(int length, int density){
    segment *res = calloc(length, sizeof(segment));
    for(int i = 0; i < length; i++) {
        if (rand() % 100 <= density) res[i].m1 = x;
        if (rand() % 100 <= density) res[i].m2 = x;
        if (rand() % 100 <= density) res[i].m3 = x;
        if (rand() % 100 <= density) res[i].m4 = x;
        if (rand() % 100 <= density) res[i].m5 = x;
        if (rand() % 100 <= density) res[i].m6 = x;
        if (rand() % 100 <= density) res[i].m7 = x;
        if (rand() % 100 <= density) res[i].m8 = x;
    }
    return res;
}

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
    for(int i = 0; i < length; i++){
        print_segment(s[i]);
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

#include <limits.h>

int get_the_best_match(const char *sequence){
    int max = INT_MIN, sum = 0;
    int length = strlen(sequence);
    for(int i = 0 ; i < length; i++){
        if(sequence[i] == 'x') sum++; else sum--;
        if(max < sum) max = sum;
        if(sum < 0) sum = 0;
    }
    return max;
}

int main(){
    srand(time(NULL));
    int len = 10;
    segment *test1 = generate_segments(len, 70);
    char *seg = convert_segments_to_string(test1, len);
    printf("%s", seg);
    puts("");
    printf("%d\n", get_the_best_match(seg));
    free(seg);
    free(test1);
}







