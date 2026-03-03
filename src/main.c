#include "array.h"
#include "render.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int  main(){

    // setup for random nummbers in array.c
    srand(time(NULL));

    // initilize array
    int *array = create_array(5);
    render_array(array, 5);

    free(array);
    return 0;
}
