#include "array.h"
#include "render.h"
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int  main(){

    // setup for random nummbers in array.c
    srand(time(NULL));

    // initilize array
    int *array = create_array(5);
    render_array(array, 5);

    int *a = copy_array(array, 5);
    int *b = copy_array(array, 5);
    int *c = copy_array(array, 5);

    // Bubble sort
    printf("Bubblesort: \n");
    bubble_sort(a, 5);
    render_array(a, 5);

    // Mergesort
    printf("Mergesort: \n");
    merge_sort(b, 0, 4);
    render_array(b, 5);

    // Quicksort
    printf("Quicksort: \n");
    quick_sort(c, 0, 4);
    render_array(c, 5);

    printf("Finished! :)");

    free(a);
    free(b);
    free(c);

    free(array);
    return 0;
}
