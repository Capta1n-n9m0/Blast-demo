#ifndef BLAST_DEMO_BLAST_CORE_H
#define BLAST_DEMO_BLAST_CORE_H


typedef struct best_match_{
    int pos, score;
}best_match;

best_match get_blast_matches(const char *data, const char *target);


#endif //BLAST_DEMO_BLAST_CORE_H
