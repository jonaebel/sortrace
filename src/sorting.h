#ifndef SORTING_H
#define SORTING_H

// Structs & Enum

#include "histroy.h"
typedef enum SortAlgorithms{
    BubbleSort,
    MergeSort,
    QuickSort
} SortAlgorithms;

typedef struct Sorter {
    char name[50];
    double time;
    SortAlgorithms algorithm;
    HistoryNode *history;
    int *to_sort;
    int n;
    int steps;
} Sorter;


Sorter *create_sorter(char name[50], SortAlgorithms algorithm, int *to_sort, int n);

void free_sorter(Sorter *sorter);

// Helper functions

// swaps the values of two pointer elements
void swap(int *x, int *y);

// helper for quicksort -> does partioning
int partition(int *array, int low, int high);

// merge sort helper
void merge(int arr[], int l, int m, int r);

// Bubblesort algorithm
void bubble_sort(Sorter *sorter);

//  Mergesort algorithm
void merge_sort(Sorter *sorter, int l, int r);

// Quicksort algorithm (maybe enum to choose which pivot to choose ? )
void quick_sort(Sorter *sorter,  int low, int high);

#endif
