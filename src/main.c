#include "array.h"
#include "histroy.h"
#include "render.h"
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int N = 10;

int  main(){

    // setup for random nummbers in array.c
    srand(time(NULL));

    // initilize array
    int *array = create_array(N);
    render_array(array, N);

    int *a = copy_array(array, N);
    int *b = copy_array(array, N);
    int *c = copy_array(array, N);

    Sorter *bubble = create_sorter("Bubblesort", BubbleSort, a, N);
    Sorter *merge = create_sorter("Mergesort", MergeSort, b, N);
    Sorter *quick = create_sorter("Quicksort", QuickSort, c, N);

    // Bubble sort
    printf("Bubblesort: \n");
    bubble_sort(bubble);
    print_history(bubble->history, bubble->n);

    // Mergesort
    printf("Mergesort: \n");
    merge_sort(merge, 0, (merge->n)-1);
    print_history(merge->history, merge->n);

    // Quicksort
    printf("Quicksort: \n");
    quick_sort(quick, 0, (quick->n)-1);
    print_history(quick->history, quick->n);

    printf("Finished! :)");

    free_sorter(bubble);
    free_sorter(merge);
    free_sorter(quick);

    free(array);
    return 0;
}
