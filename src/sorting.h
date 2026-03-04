#ifndef SORTING_H
#define SORTING_H

// Helper functions

// swaps the values of two pointer elements
void swap(int *x, int *y);

// helper for quicksort -> does partioning
int partition(int *array, int low, int high);

// merge sort helper
void merge(int arr[], int l, int m, int r);

// Bubblesort algorithm
void bubble_sort(int *array, int n);

//  Mergesort algorithm
void merge_sort(int *array, int l, int r);

// Quicksort algorithm (maybe enum to choose which pivot to choose ? )
void quick_sort(int *array, int low, int high);

#endif
