#include "blast-core.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

best_match process_matches(const char *matches){
    int length = strlen(matches);
    int max_global = -1, max_local = 0;
    int global_max_start = 0, local_max_start = 0;
    for(int i = 0; i < length; i++){
        if(matches[i] == '1') max_local++; else max_local--;
        if(max_global < max_local){
            max_global = max_local;
            global_max_start = local_max_start;
        }
        if(max_local < 0){
            max_local = 0;
            local_max_start = i;
        }
    }
    return (best_match){global_max_start+1, max_global};
}

best_match get_blast_matches(const char *data, const char *target){
    int data_length = strlen(data), target_length = strlen(target);
    int max_global = -1, max_local = 0;
    int global_max_start = 0, local_max_start = 0;
    for(int i = 0; i < data_length-target_length; i++){
        for(int j = 0; j < target_length; j++){
            if(data[i+j] == target[j]) max_local++; else max_local--;
            if(max_global < max_local){
                max_global = max_local;
                global_max_start = local_max_start;
            }
            if(max_local < 0){
                max_local = 0;
                local_max_start = i+j;
            }
        }
        max_local = 0;
    }
    return (best_match){global_max_start, max_global};
}


