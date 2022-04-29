#ifndef BLAST_DEMO_BLAST_CORE_H
#define BLAST_DEMO_BLAST_CORE_H


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

typedef struct best_match_{
    int pos, score;
}best_match;

void print_segment(segment s);
void print_segments(segment *s, int length);
char *convert_segments_to_string(segment *s, int length);
best_match get_the_best_match(const char *sequence);
best_match get_blast_matches(const char *data, const char *target);





#endif //BLAST_DEMO_BLAST_CORE_H
