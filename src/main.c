#include "array.h"
#include "histroy.h"
#include "render.h"
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int N = 100;

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
    //printf("Bubblesort: \n");
    clock_t start = clock();
    bubble_sort(bubble);
    clock_t end = clock();
    bubble->time = (double)(end - start) / CLOCKS_PER_SEC;
    bubble->steps = get_steps(bubble->history);

    //print_history(bubble->history, bubble->n);

    // Mergesort
    //printf("Mergesort: \n");
    start = clock();
    merge_sort(merge, 0, (merge->n)-1);
    end = clock();
    merge->time = (double)(end - start) / CLOCKS_PER_SEC;
    merge->steps = get_steps(merge->history);

   // print_history(merge->history, merge->n);

    // Quicksort
    //printf("Quicksort: \n");
    start = clock();
    quick_sort(quick, 0, (quick->n)-1);
    end = clock();
    quick->time = (double)(end - start) / CLOCKS_PER_SEC;
    quick->steps = get_steps(quick->history);

    //print_history(quick->history, quick->n);

    printf("=== RESULTS ===\n");
    printf("%s: %d steps, %.6f seconds\n", bubble->name, bubble->steps, bubble->time);
    printf("%s: %d steps, %.6f seconds\n", merge->name, merge->steps, merge->time);
    printf("%s: %d steps, %.6f seconds\n", quick->name, quick->steps, quick->time);


    free_sorter(bubble);
    free_sorter(merge);
    free_sorter(quick);

    free(array);
    return 0;
}
