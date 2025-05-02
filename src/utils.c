#include <stdlib.h>
#include <string.h>
#include "utils.h"


char* shift_args(int *argc, char ***argv) {
	if (!(*argc > 0)) exit(-1);
    char *result = (**argv);
    (*argv) += 1;
    (*argc) -= 1;
    return result;
}
void resetString(void* array){
	memset(array, 0, sizeof(*array));
}
