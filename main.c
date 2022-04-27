#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "blast-core.h"
#include "blast-generators.h"

int main(){
    srand(time(NULL));
    printf("8-bit segment takes %ld bytes of memory\n", sizeof(segment));

    int len = 3;

    double target_density = 0.55;
    segment *segment = generate_segments(len, target_density);
    double actual_density = check_segment_density(segment, len);

    printf("Target density: %f; Actual density: %f\n", target_density, actual_density);
    char *seg = convert_segments_to_string(segment, len);
    print_segments(segment, len);
    best_match res = get_the_best_match(seg);
    printf("pos: %d, len: %d\n", res.pos, res.score);
    char *string = generate_random_string("AGTC", 120);
    char *target = generate_random_string("AGTC", 8);
    printf("%s\n", string);
    printf("%s\n", target);


    free(string);
    free(target);
    free(seg);
    free(segment);
}

