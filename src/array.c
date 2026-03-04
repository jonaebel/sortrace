#include "array.h"
#include <stdio.h>
#include <stdlib.h>

//Fill the given array at pointer a with n random nummbers
void fill_array(int n, int *a){
    for(int i = 0 ; i<n; i++){
        a[i] = rand() % 10;
    }
}

//Creates and returns a pointer to array a length n with random numbers
int *create_array(int n){
    int *array = malloc(sizeof(int) * n);
    fill_array(n, array);

    return array;
}


int *copy_array(int *array, int n){
    int *copy = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        copy[i] = array[i];
    }

    return copy;
}
