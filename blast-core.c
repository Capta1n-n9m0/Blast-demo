#include "blast-core.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

best_match get_blast_matches(const char *data, const char *target){
    int data_length = strlen(data), target_length = strlen(target);
    int max_global = -1, max_local = 0;
    int global_max_start = 0, local_max_start = 0;
    for(int i = 0; i < data_length; i++){
        if(data[i] == target[i%target_length]) max_local++; else max_local--;
        if(max_global < max_local){
            max_global = max_local;
            global_max_start = local_max_start;
        }
        if(max_local < 0){
            max_local = 0;
            local_max_start = i;
        }
    }
    return (best_match){global_max_start, max_global};
}


