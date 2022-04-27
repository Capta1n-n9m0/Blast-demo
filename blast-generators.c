#include "blast-generators.h"
#include <stdlib.h>
#include <string.h>

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

char *generate_random_string(const char *alphabet, int length){
    int a_len = strlen(alphabet);
    char *res = calloc(length+1, sizeof(char ));

    for(int i = 0; i < length; i++)
        res[i] = alphabet[rand()%a_len];

    return res;
}

