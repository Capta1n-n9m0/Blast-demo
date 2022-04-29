#include "blast-generators.h"
#include <stdlib.h>
#include <string.h>


char *generate_random_string(const char *alphabet, int length){
    int a_len = strlen(alphabet);
    char *res = calloc(length+1, sizeof(char ));

    for(int i = 0; i < length; i++)
        res[i] = alphabet[rand()%a_len];

    return res;
}

