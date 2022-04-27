#ifndef BLAST_DEMO_BLAST_GENERATORS_H
#define BLAST_DEMO_BLAST_GENERATORS_H
#include "blast-core.h"

segment *generate_segments(int length, double density);
double check_segment_density(segment *s, int length);
char *generate_random_string(const char *alphabet, int length);









#endif //BLAST_DEMO_BLAST_GENERATORS_H
