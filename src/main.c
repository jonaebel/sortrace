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

    Sorter *bubble = create_sorter("Bubblesort", BubbleSort, a, 5);
    Sorter *merge = create_sorter("Mergesort", MergeSort, b, 5);
    Sorter *quick = create_sorter("Quicksort", QuickSort, c, 5);

    // Bubble sort
    printf("Bubblesort: \n");
    bubble_sort(bubble->to_sort, bubble->n);
    render_array(bubble->to_sort, bubble->n);

    // Mergesort
    printf("Mergesort: \n");
    merge_sort(merge->to_sort, 0, (merge->n)-1);
    render_array(merge->to_sort, merge->n);

    // Quicksort
    printf("Quicksort: \n");
    quick_sort(quick->to_sort, 0, (quick->n)-1);
    render_array(quick->to_sort, quick->n);

    printf("Finished! :)");

    free_sorter(bubble);
    free_sorter(merge);
    free_sorter(quick);

    free(array);
    return 0;
}
