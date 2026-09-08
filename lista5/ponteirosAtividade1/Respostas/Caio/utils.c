#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int TrocaInterios(int *n1, int *n2) {
    if ((*n1) > (*n2)) {
        int auxiliar = *n1;
        *n1 = *n2;
        *n2 = auxiliar;

        return 1;
    }
    return 0;
}
