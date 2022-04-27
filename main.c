#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define SEGMENTS_PER_LINE 20

// o is zero
// x is one
typedef enum match_{
    o, x
} __attribute__((packed)) match;

typedef struct segment_{
    match m1: 1;
    match m2: 1;
    match m3: 1;
    match m4: 1;
    match m5: 1;
    match m6: 1;
    match m7: 1;
    match m8: 1;
} __attribute__((packed)) segment;

segment *generate_segments(int length, double density);
void print_segment(segment s);
void print_segments(segment *s, int length);
char *convert_segments_to_string(segment *s, int length);
int get_the_best_match(const char *sequence);
double check_segment_density(segment *s, int length);


int main(){
    srand(time(NULL));
    printf("8bit segment takes %ld bytes of memory\n", sizeof(segment));

    int len = 10000;
    double target_density = 0.55;
    segment *test1 = generate_segments(len, target_density);
    double actual_density = check_segment_density(test1, len);

    printf("Target density: %f; Actual density: %f\n", target_density, actual_density);
    char *seg = convert_segments_to_string(test1, len);
    //print_segments(test1, len);
    puts("");
    printf("%d\n", get_the_best_match(seg));
    free(seg);
    free(test1);
}


segment *generate_segments(int length, double density){
    segment *res = calloc(length, sizeof(segment));
    for(int i = 0; i < length; i++) {
        if (((double)rand() / RAND_MAX) < density) res[i].m1 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m2 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m3 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m4 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m5 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m6 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m7 = x;
        if (((double)rand() / RAND_MAX) < density) res[i].m8 = x;
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

double check_segment_density(segment *s, int length){
    int c = 0;
    for(int i = 0; i < length; i++){
        if(s[i].m1 == x) c++;
        if(s[i].m2 == x) c++;
        if(s[i].m3 == x) c++;
        if(s[i].m4 == x) c++;
        if(s[i].m5 == x) c++;
        if(s[i].m6 == x) c++;
        if(s[i].m7 == x) c++;
        if(s[i].m8 == x) c++;
    }
    return (double)c/(length * 8);
}




