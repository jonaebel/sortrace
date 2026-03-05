#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "histroy.h"


Sorter *create_sorter(char *name, SortAlgorithms algorithm, int *to_sort, int n){
    Sorter *sorter = malloc(sizeof(Sorter));
    HistoryNode *head;
    create_history(&head, to_sort, n);
    sorter->history = head;
    sorter->algorithm = algorithm;
    sorter->to_sort = to_sort;
    sorter->n = n;
    sorter->time = 0.0;
    sorter->steps = 0;
    strcpy(sorter->name, name);
    return sorter;
}

void free_sorter(Sorter *sorter){
    free(sorter->to_sort);
    free(sorter);
}

void swap(int *x, int *y){
    int temp = *x;
       *x = *y;
       *y = temp;
}

int partition(int *array, int low, int high){
        // choose the pivot -> Highest for now maybe using enum later on
        int pivot = array[high];

        // index of smaller element and indicates the right position of pivot found so far
        int i = low - 1;

        // traverse arr[low..high] and move all smaller elements to the left side
        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                swap(&array[i], &array[j]);
            }
        }

        // moves pivot and returns position
        swap(&array[i + 1], &array[high]);
        return i + 1;
}


void merge(int arr[], int l, int m, int r){

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void bubble_sort(Sorter *sorter){
    int *array = sorter->to_sort;
    int n = sorter->n;
    int i, j = 0;
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(&array[j],&array[j + 1]);
                    add_result(sorter->history, array, sorter->n);
                }
            }
        }
}

void quick_sort(Sorter *sorter, int low, int high){
    if (low < high) {

            // pi is the partition return index of pivot
            int pi = partition(sorter->to_sort, low, high);

            // recursion calls for smaller elements
            // and greater or equals elements
            quick_sort(sorter, low, pi - 1);
            quick_sort(sorter, pi + 1, high);
            add_result(sorter->history, sorter->to_sort, sorter->n);
        }
}

void merge_sort(Sorter *sorter, int l, int r){

    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(sorter, l, m);
        merge_sort(sorter, m + 1, r);

        merge(sorter->to_sort, l, m, r);
        add_result(sorter->history, sorter->to_sort, sorter->n);
    }
}
